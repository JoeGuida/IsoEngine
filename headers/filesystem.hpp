#ifndef ISOENGINE_FILESYSTEM_HPP
#define ISOENGINE_FILESYSTEM_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class FileSystem final {
private:
    static std::string get_root() {
        const char* env = std::getenv("ISOENGINE_ROOT");

        if (!env) {
            std::cout << "ERROR::FILESYSTEM Error reading environment variable: ISOENGINE_ROOT" << std::endl;
            return nullptr;
        }
        return std::string(env);
    }

public:
    static std::string get_path(const char* path) {
        std::string root = get_root();

        if (root.empty())
            return nullptr;

        return std::string(root + path);
    }
};

#endif