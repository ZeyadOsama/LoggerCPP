//
// Created by zeyad-osama on 25/07/2020.
//

#pragma once

#include <Base/Channel.h>
#include <Utils/DataTypes/SharedPointer.h>

#include <vector>
#include <typeinfo>

namespace Log {

    /**
     * @brief Output Interface
     */
    class Output {
    public:
        typedef shared_ptr <Output> Pointer;
        typedef std::vector<Pointer> Vector;

    public:
        virtual ~Output() = default;

        virtual void Out(const Channel::Pointer &channel, const Log &log) const = 0;

        virtual void Terminate() const = 0;

        inline const char *name() const {
            return typeid(this).name();
        }
    };
}