//
// Created by miroslav.vasilev on 21.8.2018 г..
//

#ifndef VOXPLORER_VERTEX_HPP
#define VOXPLORER_VERTEX_HPP

#include <glad/glad.h>

#include <glm/glm.hpp>

static const GLuint _VERTEX_POSITION_LOCATION = 0;
static const GLuint _VERTEX_UV_LOCATION = 1;
static const GLuint _VERTEX_NORMAL_LOCATION = 2;

struct Vertex {

    glm::vec3 position;
    glm::vec2 uv;
    glm::vec3 normal;

    Vertex(const glm::vec3 &position, const glm::vec2 &uv, const glm::vec3 &normal)
        : position(position), uv(uv), normal(normal)
    {

    }

    static void bindAttributes(GLuint program) {
        glBindAttribLocation(program, _VERTEX_POSITION_LOCATION, "position");
        glBindAttribLocation(program, _VERTEX_UV_LOCATION, "uv");
        glBindAttribLocation(program, _VERTEX_NORMAL_LOCATION, "normal");
    }

    static void fillVertexArrayObject() {
        glEnableVertexAttribArray(_VERTEX_POSITION_LOCATION);
        glVertexAttribPointer(_VERTEX_POSITION_LOCATION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) 0);

        glEnableVertexAttribArray(_VERTEX_UV_LOCATION);
        glVertexAttribIPointer(_VERTEX_UV_LOCATION, 2, GL_FLOAT, sizeof(Vertex), (void *) (3 * sizeof(GLfloat)));
    
        glEnableVertexAttribArray(_VERTEX_NORMAL_LOCATION);
        glVertexAttribIPointer(_VERTEX_NORMAL_LOCATION, 3, GL_FLOAT, sizeof(Vertex), (void *) (5 * sizeof(GLfloat)));
    }

};


#endif //VOXPLORER_VERTEX_HPP
