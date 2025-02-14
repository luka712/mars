//
// Created by lukaa on 11.1.2025..
//

#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>

namespace mars {
    class Framework;

    //! The file reader.
    class FileReader {
    public:
        //! Construct a new FileReader object.
        //! @param framework The framework.
        explicit FileReader(Framework &framework);

        //! Read a file from the file system.
        //! @param filePath The path to the file.
        //! @return The content of the file.
        [[nodiscard]] std::string readFile(const std::string& filePath) const;
    private:
        Framework& framework;
    };
}

#endif //FILEREADER_H
