//
// Created by zeyad-osama on 25/07/2020.
//

#pragma once

#define LOG_OUT_DIR "log/"

#include <iostream>
#include <Utils/DataTypes/Severity.h>

namespace Log {

#define STR_TO_CHR(a) ((char *)std::string(a).c_str())
#define CAT_STR_TO_CHR(a, b) ((char *)std::string(a+b).c_str())

    const char *to_string(SEVERITY aSeverity);

    SEVERITY to_level(const std::string &aSeverity);

    unsigned int to_escape_code(SEVERITY aSeverity);
}