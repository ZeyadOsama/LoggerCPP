//
// Created by zeyad-osama on 16/08/2020.
//

#ifndef LOGGER_COMMON_OPTIONS_OPTION_STREAM_HPP
#define LOGGER_COMMON_OPTIONS_OPTION_STREAM_HPP

namespace logger {
    namespace options {

        struct OUTPUT_STREAM {
        public:
            static constexpr const char *CONSOLE = "OutputConsole";
            static constexpr const char *FILE = "OutputFile";

        private:
            OUTPUT_STREAM() = default;
        };
    } //namespace options
} //namespace logger

#endif //LOGGER_COMMON_OPTIONS_OPTION_STREAM_HPP