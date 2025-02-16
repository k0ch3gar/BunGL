#ifndef OBJPARSER_HPP
#define OBJPARSER_HPP
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "glm/vec3.hpp"

class ObjParser {
public:
    ObjParser() = default;

    void parseOBJFile(const std::string& filePath) {
        _faces.clear();
        _vertices.clear();
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Не удалось открыть файл: " << filePath << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type;
            iss >> type;

            if (type == "v") {
                glm::vec3 vertex;
                iss >> vertex.x >> vertex.y >> vertex.z;
                _vertices.push_back(vertex.x);
                _vertices.push_back(vertex.y);
                _vertices.push_back(vertex.z);
            } else if (type == "f") {
                std::string v1, v2, v3, v4;
                iss >> v1 >> v2 >> v3 >> v4;

                auto extractVertexIndex = [](const std::string& s) {
                    size_t pos = s.find('/');
                    return std::stoi(s.substr(0, pos)) - 1;
                };

                _faces.emplace_back(extractVertexIndex(v1));
                _faces.emplace_back(extractVertexIndex(v2));
                _faces.emplace_back(extractVertexIndex(v3));
                if (!v4.empty()) {
                    _faces.emplace_back(extractVertexIndex(v1));
                    _faces.emplace_back(extractVertexIndex(v3));
                    _faces.emplace_back(extractVertexIndex(v4));
                }
            }
        }

        file.close();
    }

    std::vector<float>& getVertices() { return _vertices; }

    std::vector<unsigned int>& getFaces() { return _faces; }

private:
    std::vector<float> _vertices;
    std::vector<unsigned int> _faces;
};

#endif //OBJPARSER_HPP
