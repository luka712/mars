//
// Created by lukaa on 11.1.2025..
//

#include <fstream>
#include "Framework.h"
#include "core/loaders/FileLoader.h"

namespace mars {

    FileLoader::FileLoader(Framework &framework)
        : framework(framework) {
    }

    std::string FileLoader::loadFile( std::string filePath) {
        std::ifstream fileStream(filePath);
        if (!fileStream.is_open()) {
            const std::string msg = "FileLoader::loadFile: Cannot open file: " + filePath;
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        std::string content;
        std::string line;
        while (std::getline(fileStream, line)) {
            content += line + "\n";
        }
        fileStream.close();
        return content;
     }

}