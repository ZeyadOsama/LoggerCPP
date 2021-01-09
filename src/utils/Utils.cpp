//
// Created by zeyad-osama on 16/08/2020.
//

#include <logger/utils/Utils.hpp>
#include <logger/utils/ConsoleColors.hpp>

namespace logger {
    namespace utils {

        const char *to_string(SEVERITY aSeverity) {
            switch (aSeverity) {
                case DEBUG:
                    return "DBUG";
                case INFO:
                    return "INFO";
                case NOTE:
                    return "NOTE";
                case WARN:
                    return "WARN";
                case ERROR:
                    return "EROR";
                case CRTC:
                    return "CRIT";
            }
            return "????";
        }

        SEVERITY to_level(const std::string &aSeverity) {
            if (aSeverity == "DBUG")
                return DEBUG;
            else if (aSeverity == "INFO")
                return INFO;
            else if (aSeverity == "NOTE")
                return NOTE;
            else if (aSeverity == "WARN")
                return WARN;
            else if (aSeverity == "EROR")
                return ERROR;
            else if (aSeverity == "CRTC")
                return CRTC;
            return CRTC;
        }

        unsigned int to_escape_code(SEVERITY aSeverity) {
            switch (aSeverity) {
                case DEBUG:
                    return BLUE;
                case INFO:
                    return WHITE;
                case NOTE:
                    return GREEN;
                case WARN:
                    return ORANGE;
                case ERROR:
                    return RED;
                case CRTC:
                    return MAGENTA;
            }
            return WHITE;
        }

    } //namespace utils
} //namespace logger