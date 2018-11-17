cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fsanitize=undefined,address -DHAZARD_DEBUG")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined,address -DHAZARD_DEBUG")
set(PROJECT_NAME Hazard)
set(HAZARD_VERSION 0.1)
set(HAZARD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HAZARD_RES ${CMAKE_CURRENT_SOURCE_DIR}/res)
set(HAZARD_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(HAZARD_BIN ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${HAZARD_BIN})

project(${PROJECT_NAME})

file(GLOB_RECURSE HAZARD_HEADERS ${HAZARD_SRC}/*.h )
file(GLOB_RECURSE HAZARD_CPP_SOURCES ${HAZARD_SRC}/*.cpp )
file(GLOB_RECURSE HAZARD_C_SOURCES ${HAZARD_SRC}/*.c )


add_executable(${PROJECT_NAME} 
    ${HAZARD_HEADERS} 
    ${HAZARD_CPP_SOURCES} 
    ${HAZARD_C_SOURCES}
)

# GLFW
set(GLFW_DIR ${HAZARD_LIB}/glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

add_subdirectory(${GLFW_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_DIR}/include)
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})

# GLM
set(GLM_DIR ${HAZARD_LIB}/glm)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLM_DIR})

# GLAD
set(GLAD_DIR ${HAZARD_LIB}/glad)
add_library("glad" ${GLAD_DIR}/src/glad.c)

target_include_directories("glad" PRIVATE ${GLAD_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)
target_link_libraries(${PROJECT_NAME} "glad" ${CMAKE_DL_LIBS})

# Nlohmann/Json
set(JSON_DIR ${HAZARD_LIB}/json)

add_library("json" ${JSON_DIR}/single_include/nlohmann/json.hpp)

set_target_properties("json" PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories("json" PRIVATE ${JSON_DIR}/single_include/nlohmann)
target_include_directories(${PROJECT_NAME} PRIVATE ${JSON_DIR}/single_include/nlohmann)
target_link_libraries(${PROJECT_NAME} "json" ${CMAKE_DL_LIBS})

# FreeType
set(FREETYPE_DIR ${HAZARD_LIB}/freetype)

# set(JSON_DIR ${HAZARD_LIB}/json)
# add_library("json" ${JSON_DIR}/single_include/nlohmann/json.hpp)

# target_include_directories("json" PRIVATE ${JSON_DIR}/single_include)
# target_include_directories(${PROJECT_NAME} PRIVATE ${JSON_DIR}/single_include)
# target_link_libraries(${PROJECT_NAME} "json" ${CMAKE_DL_LIBS})

# gason
# set(GASON_DIR ${HAZARD_LIB}/gason)
# add_library("gason" ${GASON_DIR}/src/gason.cpp ${GASON_DIR}/src/gason.h)

# target_include_directories("gason" PRIVATE ${GASON_DIR}/src)
# target_include_directories(${PROJECT_NAME} PRIVATE ${GASON_DIR}/src)
# target_link_libraries(${PROJECT_NAME} "gason" ${CMAKE_DL_LIBS})

target_include_directories(${PROJECT_NAME} PRIVATE ${HAZARD_SRC})

# file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/res)
file(COPY ${HAZARD_RES} DESTINATION ${HAZARD_BIN})