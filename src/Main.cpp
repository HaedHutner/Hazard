#include <iostream>
#include <GL/gl.h>

int main(int argc, char const *argv[])
{
    std::cout << glGetString(GL_VERSION) << "\n";
    std::cout << "Hello world!" << "\n";
    /* code */
    return 0;
}
