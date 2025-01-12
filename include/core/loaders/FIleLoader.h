//
// Created by lukaa on 11.1.2025..
//

#ifndef FILELOADER_H
#define FILELOADER_H

#include <string>

namespace mars {
    class Framework;

    class FileLoader {
    public:
        //! Construct a new FileLoader object.
        //! @param framework The framework.
        explicit FileLoader(Framework &framework);

        //! Load a file from the file system.
        //! @param filePath The path to the file.
        //! @return The content of the file.
        std::string loadFile(std::string filePath);
    private:
        Framework& framework;
    };
}

#endif //FILELOADER_H
