#ifndef VOXPLORER_GAME_H
#define VOXPLORER_GAME_H

#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "event/EventDispatcher.h"

#include "GameState.h"

class Game {

protected:

    GLFWwindow *window;

    std::unique_ptr<GameState> state;

    EventDispatcher eventDispatcher;

    int width = 800, height = 600;
    std::string name = "Default Name";

    glm::vec3 background = {0.5f, 0.2f, 0.5f};

    double lastTickDuration = 0.0;

public:

    GLFWwindow *getWindow() const;

    void setClearColor(const glm::vec3 &color);

    double getLastTickDuration() const;

    virtual bool init();

    virtual void run();

    virtual void processInputs() {
        state->processInputs(window);
    }

    virtual void update() {
        glfwPollEvents();
        state->update();
    }

    virtual void render() {
        glClear(GL_COLOR_BUFFER_BIT);
        state->render(window);
        glfwSwapBuffers(window);
    }
};


#endif //VOXPLORER_GAME_H
