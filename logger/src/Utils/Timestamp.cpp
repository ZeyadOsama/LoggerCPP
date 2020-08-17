//
// Created by zeyad-osama on 25/07/2020.
//

#include <Utils/Timestamp.h>
#include <time.h>
#include <sys/time.h>

namespace Log {

    Timestamp::Timestamp() :
            year(0),
            month(0),
            day(0),
            hour(0),
            minute(0),
            second(0),
            ms(0),
            us(0) {
    }

    void Timestamp::Generate() {
        struct timeval now{};
        gettimeofday(&now, nullptr);
        struct tm *time_info = localtime(&now.tv_sec);

        year = time_info->tm_year + 1900;
        month = time_info->tm_mon + 1;
        day = time_info->tm_mday;
        hour = time_info->tm_hour;
        minute = time_info->tm_min;
        second = time_info->tm_sec;
        ms = static_cast<int>(now.tv_usec / 1000);
        us = static_cast<int>(now.tv_usec % 1000);
    }
}