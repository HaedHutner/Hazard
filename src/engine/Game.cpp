#include "Game.h"

GLFWwindow *Game::getWindow() const {
    return window;
}

void Game::setClearColor(const glm::vec3 &color) {
    background = color;
    glClearColor(background.x, background.y, background.z, 0.0f);
}

bool Game::init() {
    if (!glfwInit()) {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    // glfwWindowHint(GLFW_DECORATED, GL_FALSE);

    window = glfwCreateWindow(
            width,
            height,
            name.c_str(),
            nullptr,
            nullptr
    );

    if (!window) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    glfwSwapInterval(1);

    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(background.x, background.y, background.z, 0.0f);

    return true;
}

void Game::run() {

    while (!glfwWindowShouldClose(window)) {

        double before = glfwGetTime();

        glfwPollEvents();

        processInputs();
        update();
        render();

        double after = glfwGetTime();

        Game::lastTickDuration = after - before;
        log_info("Last frame took %dms", (int) ( ( after - before ) * 1000 ));
        //printf("Last frame took %dms", (int) ( ( after - before ) * 1000 ));
    }

    glfwTerminate();
}

double Game::getLastTickDuration() const {
    return lastTickDuration;
}
