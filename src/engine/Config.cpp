#include "Config.h"

Config::Config(const std::string &filePath)
{
    std::ifstream file(filePath);
    std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    j = json::parse(contents);
}

const json &Config::find(const json &node, std::deque<std::string> path) const {
    auto n = path.front();
    path.pop_front();

    if (node.find(n) != node.end()) {
        if (node[n].is_object() || node[n].is_array()) {
            return find(node[n], path);
        }
        else return node[n];
    }

    return node;
}

bool Config::getBool(const std::deque<std::string> &path) const {
    return get(path).get<bool>();
}

int Config::getInt(const std::deque<std::string> &path) const {
    return get(path).get<int>();
}

double Config::getDouble(const std::deque<std::string> &path) const {
    return get(path).get<double>();
}

std::string Config::getString(const std::deque<std::string> &path) const {
    return get(path).get<std::string>();
}

const json &Config::get(const std::deque<std::string> &path) const {
    return find(j, path);
}

Config::~Config()
{
}