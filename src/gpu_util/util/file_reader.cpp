//
// Created by Erkapic Luka on 2.7.2025.
//

#include "gpu_util/util/file_reader.h"
#include <fstream>
#include <sstream>

namespace gpu_util {

    //! Reads a file and returns its content as a string.
    //! @param filePath The path to the file to read.
    //! @return The content of the file as a string.
    std::string FileReader::readFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filePath);
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

} // namespace gpu_util