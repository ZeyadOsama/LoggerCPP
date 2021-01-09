//
// Created by zeyad-osama on 16/08/2020.
//

#ifndef LOGGER_COMMON_OPTIONS_OPTIONS_HPP
#define LOGGER_COMMON_OPTIONS_OPTIONS_HPP

namespace logger {
    namespace options {

        struct OPTION {
        public:
            static constexpr const char *FILE_NAME = "filename";
            static constexpr const char *MAX_FILES = "10";

        private:
            OPTION() = default;
        };
    } //namespace options
} //namespace logger

#endif //LOGGER_COMMON_OPTIONS_OPTIONS_HPP