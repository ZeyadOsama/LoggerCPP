//
// Created by zeyad-osama on 16/08/2020.
//

#pragma once

namespace Log {

    struct OUTPUT_STREAM {
    public:
        static constexpr const char *CONSOLE = "OutputConsole";
        static constexpr const char *FILE = "OutputFile";

    private:
        OUTPUT_STREAM() = default;
    };
}
