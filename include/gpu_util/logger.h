
#ifndef GPU_UTIL_LOGGER_H

#define GPU_UTIL_LOGGER_H

#include <string>

namespace gpu_util {

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

    //! The spdlog implementation of a \see Logger
    class SpdLogger final : public Logger {
    public:
        void info(const char *msg) override;

        void warn(const char *msg) override;

        void error(const char *msg) override;
    };

    //! The mock implementation of a \see Logger.
    //! Does not do anything.
    class MockLogger final : public Logger {
    public:
        void info(const char *msg) override;

        void warn(const char *msg) override;

        void error(const char *msg) override;
    };
}

#endif