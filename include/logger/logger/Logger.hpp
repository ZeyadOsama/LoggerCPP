//
// Created by zeyad-osama on 25/07/2020.
//

#ifndef LOGGER_LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_LOGGER_HPP

#include <logger/common/dataunits/Log.hpp>
#include <logger/common/Channel.hpp>
#include <logger/configurations/Manager.hpp>
#include <logger/common/datatypes/Severity.hpp>

#include <string>

namespace logger {

    /// Forward declaration
    class Log;

    class Logger {
        friend class Log;

    public:
        explicit Logger(const char *ChannelName) {
            mChannelPointer = configurations::Manager::Get(ChannelName);
        }

        ~Logger() = default;

        inline const char *GetName() const {
            return mChannelPointer->GetName();
        }

        inline void SetSeverity(SEVERITY severity) {
            mChannelPointer->SetSeverity(severity);
        }

        inline SEVERITY GetSeverity() const {
            return mChannelPointer->GetSeverity();
        }

        inline Log debug() const {
            return Log(*this, DEBUG);
        }

        inline Log info() const {
            return Log(*this, INFO);
        }

        inline Log notice() const {
            return Log(*this, NOTE);
        }

        inline Log warn() const {
            return Log(*this, WARN);
        }

        inline Log error() const {
            return Log(*this, ERROR);
        }

        inline Log critic() const {
            return Log(*this, CRTC);
        }

    private:
        inline void Out(const Log &log) const {
            configurations::Manager::Out(mChannelPointer, log);
        }

    private:
        Channel::Pointer mChannelPointer;
    };
} //namespace logger

#endif //LOGGER_LOGGER_LOGGER_HPP