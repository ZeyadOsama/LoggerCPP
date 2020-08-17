//
// Created by zeyad-osama on 16/08/2020.
//

#pragma once

namespace Log {

    struct OPTION {
    public:
        static constexpr const char *FILE_NAME = "filename";
        static constexpr const char *MAX_FILES = "10";

    private:
        OPTION() = default;
    };
}