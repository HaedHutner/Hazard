#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <deque>

#include <json.hpp>

using namespace nlohmann;

class Config {
private:

    json j;

    const json &find(const json &node, std::deque<std::string> path) const;

public:
    Config(const std::string &filePath);

    std::string getString(const std::deque<std::string> &path) const;

    double getDouble(const std::deque<std::string> &path) const;

    int getInt(const std::deque<std::string> &path) const;

    bool getBool(const std::deque<std::string> &path) const;

    const json &get(const std::deque<std::string> &path) const;

    ~Config();
};

#endif
