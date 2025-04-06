//
// Created by Erkapic Luka on 2.4.2025.
//

#ifndef RESULT_H
#define RESULT_H

#include <string>

namespace asset_toolkit {
    //! The Result class.
    template<typename T>
    struct Result {
        //! Indicates if the operation was successful.
        bool isSuccess{};

        //! The value of the operation.
        T value;

        //! The message of the operation in case of failure.
        std::string message;

        //! Create a new success result.
        //! @param value The value of the operation.
        static Result<T> success(T value) {
            return  {true, value, ""};
        }

        //! Create a new error result.
        //! @param message The reason of the error.
        static Result<T> error(const std::string &message) {
            return  {false, {}, message};
        }
    };
}

#endif //RESULT_H
