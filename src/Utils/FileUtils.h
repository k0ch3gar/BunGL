#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <fstream>
#include <sstream>
#include <string>

inline std::ifstream ReadFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    return file;
}

#endif //FILEUTILS_H
