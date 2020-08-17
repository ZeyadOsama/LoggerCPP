//
// Created by zeyad-osama on 25/07/2020.
//

#pragma once

namespace Log {

    struct Timestamp {

        int year, month, day, hour, minute, second, ms, us;

        Timestamp();

        void Generate();
    };
}