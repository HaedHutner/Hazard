#include "Config.h"

Config::Config(const std::string &filePath)
{
    std::ifstream file(filePath);
    std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    j = json::parse(contents);
}

json Config::find(const json &node, std::deque<std::string> path) const {
    if ( path.empty() ) return {};

    auto n = path.front();
    path.pop_front();

    if (node.find(n) != node.end()) {
        if ( path.size() == 0 ) return node[n];

        if (node[n].is_object() || node[n].is_array()) {
            return find(node[n], path);
        }
    }

    return {};
}

bool Config::getBool(std::deque<std::string> path) const {
    json result = get(path);
    if ( result.empty() ) return false;
    return get(path).get<bool>();
}

int Config::getInt(std::deque<std::string> path) const {
    json result = get(path);
    if ( result.empty() ) return 0;
    return get(path).get<int>();
}

double Config::getDouble(std::deque<std::string> path) const {
    json result = get(path);
    if ( result.empty() ) return 0.0;
    return get(path).get<double>();
}

std::string Config::getString(std::deque<std::string> path) const {
    json result = get(path);
    if ( result.empty() ) return "";
    return get(path).get<std::string>();
}

glm::vec4 Config::getVec4(std::deque<std::string> path) const {
    glm::vec4 vec = {0.0f, 0.0f, 0.0f, 0.0f};
    json result = get(path);
    
    if ( !result.empty() && result.is_array() ) {
        for ( int i = 0; i < 4; i++ ) {
            if ( !result[i].empty() ) {
                vec[i] = result[i].get<double>();
            }
        }
    }

    return vec;
}

glm::vec3 Config::getVec3(std::deque<std::string> path) const {
    glm::vec3 vec = {0.0f, 0.0f, 0.0f};
    json result = get(path);

    if ( !result.empty() && result.is_array() ) {
        for ( int i = 0; i < 3; i++ ) {
            if ( !result[i].empty() ) {
                vec[i] = result[i].get<double>();
            }
        }
    }

    return vec;
}

glm::vec2 Config::getVec2(std::deque<std::string> path) const {
    glm::vec2 vec = {0.0f, 0.0f};
    json result = get(path);
    
    if ( !result.empty() && result.is_array() ) {
        for ( int i = 0; i < 2; i++ ) {
            if ( !result[i].empty() ) {
                vec[i] = result[i].get<double>();
            }
        }
    }

    return vec;
}

json Config::get(std::deque<std::string> path) const {
    return find(j, path);
}

template <typename T>
T Config::get(std::deque<std::string> path) const {
    return get(path).get<T>();
}

Config::~Config()
{
}