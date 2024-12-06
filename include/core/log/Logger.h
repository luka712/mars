//
// Created by lukaa on 30.11.2024.
//


#ifndef LOGGING_H
#define LOGGING_H


#include <string>

namespace mars {
    //! The logger class.
    class Logger {
    public:
        virtual	~Logger() {}

        //! Creates information log.
        //! @param msg The log message.
        virtual void info(const char *msg) = 0;

        //! Creates information log.
        //! @param msg The log message.
        virtual void info(const std::string& msg);

        //! Creates warning log.
        //! @param msg The log message.
        virtual void warn(const char *msg) = 0;

        //! Creates warning log.
        //! @param msg The log message.
        virtual void warn(const std::string& msg);

        //! Creates error log.
        //! @param msg The log message.
        virtual void error(const char *msg) = 0;

        //! Creates error log.
        //! @param msg The log message.
        virtual void error(const std::string& msg);

    };
}

#endif //LOGGING_H
