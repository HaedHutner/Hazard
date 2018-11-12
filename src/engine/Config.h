#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <deque>

#include <glm/glm.hpp>
#include <json.hpp>

using namespace nlohmann;

class Config {
private:

    json j;

    json find(const json &node, std::deque<std::string> path) const;

public:
    Config(const std::string &filePath);

    std::string getString(std::deque<std::string> path) const;

    double getDouble(std::deque<std::string> path) const;

    int getInt(std::deque<std::string> path) const;

    bool getBool(std::deque<std::string> path) const;

    glm::vec4 getVec4(std::deque<std::string> path) const;

    glm::vec3 getVec3(std::deque<std::string> path) const;

    glm::vec2 getVec2(std::deque<std::string> path) const;

    json get(std::deque<std::string> path) const;

    ~Config();
};

#endif
