cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fsanitize=undefined,address")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined,address")
set(PROJECT_NAME Hazard)
set(PROJECT_VERSION 0.1)
set(PROJECT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res)
set(PROJECT_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(PROJECT_BIN ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BIN})

project(${PROJECT_NAME})

add_executable(
        ${PROJECT_NAME}
        src/Main.cpp
        src/engine/Camera.cpp
        src/engine/Camera.h
        src/engine/Config.h
        src/engine/Config.cpp
        src/engine/Game.cpp
        src/engine/Game.h
        src/engine/GameState.h
        src/engine/ShaderProgram.cpp
        src/engine/ShaderProgram.h
        src/engine/Mesh.cpp
        src/engine/Mesh.h
        src/engine/Vertex.hpp
        src/engine/Renderer.h
        src/engine/Renderable.h
        src/engine/Keyboard.cpp
        src/engine/Keyboard.h
        src/game/Hazard.h
        src/game/Hazard.cpp
        src/game/state/IdleGameState.h
        src/game/state/IdleGameState.cpp
)

# GLFW
set(GLFW_DIR ${PROJECT_LIB}/glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

add_subdirectory(${GLFW_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_DIR}/include)
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})

# GLM
set(GLM_DIR ${PROJECT_LIB}/glm)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLM_DIR})

# GLAD
set(GLAD_DIR ${PROJECT_LIB}/glad)
add_library("glad" ${GLAD_DIR}/src/glad.c)

target_include_directories("glad" PRIVATE ${GLAD_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)
target_link_libraries(${PROJECT_NAME} "glad" ${CMAKE_DL_LIBS})

# Nlohmann/Json
set(JSON_DIR ${PROJECT_LIB}/json)

add_library("json" ${JSON_DIR}/single_include/nlohmann/json.hpp)

set_target_properties("json" PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories("json" PRIVATE ${JSON_DIR}/single_include/nlohmann)
target_include_directories(${PROJECT_NAME} PRIVATE ${JSON_DIR}/single_include/nlohmann)
target_link_libraries(${PROJECT_NAME} "json" ${CMAKE_DL_LIBS})

# set(JSON_DIR ${PROJECT_LIB}/json)
# add_library("json" ${JSON_DIR}/single_include/nlohmann/json.hpp)

# target_include_directories("json" PRIVATE ${JSON_DIR}/single_include)
# target_include_directories(${PROJECT_NAME} PRIVATE ${JSON_DIR}/single_include)
# target_link_libraries(${PROJECT_NAME} "json" ${CMAKE_DL_LIBS})

# gason
# set(GASON_DIR ${PROJECT_LIB}/gason)
# add_library("gason" ${GASON_DIR}/src/gason.cpp ${GASON_DIR}/src/gason.h)

# target_include_directories("gason" PRIVATE ${GASON_DIR}/src)
# target_include_directories(${PROJECT_NAME} PRIVATE ${GASON_DIR}/src)
# target_link_libraries(${PROJECT_NAME} "gason" ${CMAKE_DL_LIBS})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SRC_DIR})

# file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/res)
file(COPY ${PROJECT_RESOURCE_DIR} DESTINATION ${PROJECT_BIN})