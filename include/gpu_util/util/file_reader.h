//
// Created by lukaa on 2.7.2025..
//

#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

namespace gpu_util {

    //! A utility class for reading files.
    class FileReader {
    public:
       //! Reads the content of a file and returns it as a string.
       //! @param filePath The path to the file to read.
       //! @return The content of the file as a string.
       //! @throws std::runtime_error if the file cannot be opened or read.
       static std::string readFile(const std::string& filePath);
    };
}

#endif //FILE_READER_H
