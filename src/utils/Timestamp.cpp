//
// Created by zeyad-osama on 25/07/2020.
//

#include <logger/utils/Timestamp.hpp>
#include <time.h>
#include <sys/time.h>

using namespace logger::utils;

Timestamp::Timestamp()
        : year(0),
          month(0),
          day(0),
          hour(0),
          minute(0),
          second(0),
          ms(0),
          us(0) {}

void Timestamp::Generate() {
    struct timeval now{};
    gettimeofday(&now, nullptr);
    struct tm *time_info = localtime(&now.tv_sec);

    this->year = time_info->tm_year + 1900;
    this->month = time_info->tm_mon + 1;
    this->day = time_info->tm_mday;
    this->hour = time_info->tm_hour;
    this->minute = time_info->tm_min;
    this->second = time_info->tm_sec;
    this->ms = static_cast<int>(now.tv_usec / 1000);
    this->us = static_cast<int>(now.tv_usec % 1000);
}
