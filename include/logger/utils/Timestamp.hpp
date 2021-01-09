//
// Created by zeyad-osama on 25/07/2020.
//

#ifndef LOGGER_UTILS_TIME_STAMP_HPP
#define LOGGER_UTILS_TIME_STAMP_HPP

namespace logger {
    namespace utils {

        struct Timestamp {
        public:
            Timestamp();

            void Generate();

        public:
            int year, month, day, hour, minute, second, ms, us;
        };
    } //namespace utils
} //namespace logger

#endif //LOGGER_UTILS_TIME_STAMP_HPP