//
// Created by zeyad-osama on 25/07/2020.
//

#pragma once

#include <Utils/Timestamp.h>
#include <Utils/DataTypes/Severity.h>

#include <sstream>
#include <iomanip>

namespace Log {

    /// Forward declaration
    class Logger;

    /**
     * @brief   A RAII (private) log object constructed by the Logger class
     * <br>
     * A Log represents a full line of log, at a certain Log::Level of severity.
     *
     * <br>
     * It is constructed and initialized by a call to:
     * <li>Logger::debug() </li>
     * <li>Logger::info() </li>
     * <li>Logger::critic() </li>
     * <li>Logger::warn() </li>
     * <li>Logger::notice() </li>
     * <br>
     *
     * Is is then used by successive stream call "<<", and is naturally terminated
     * by it destructor at the end of the line, calling the Logger::Output() method.
     *
     * It contains all required information for further formatting, printing and transmitting
     * by the Logger class.
     */
    class Log {
        friend class Logger;

    public:
        template<typename T>
        Log &operator<<(const T &val) {
            if (mStream != nullptr) {
                *mStream << val;
            }
            return (*this);
        }

    public:
        ~Log();

        inline SEVERITY GetLevel() const {
            return mSeverity;
        }

        inline const Timestamp &GetTimestamp() const {
            return mTimestamp;
        }

        inline const std::ostringstream &GetStream() const {
            return *mStream;
        }

    private:
        Log(const Logger &aLogger, SEVERITY aSeverity);

        /// @{ Non-copyable object
        Log(const Log &);

        void operator=(const Log &);
        /// @}

    private:
        const Logger &mLogger;
        SEVERITY mSeverity;
        Timestamp mTimestamp;
        std::ostringstream *mStream;
    };
}