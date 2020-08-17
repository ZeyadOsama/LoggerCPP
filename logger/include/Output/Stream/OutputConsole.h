//
// Created by zeyad-osama on 25/07/2020.
//

#pragma once

#include <Output/Output.h>
#include <Base/Configuration.h>

namespace Log {

    class OutputConsole : public Output {
    public:
        explicit OutputConsole(const Configuration::Pointer &apConfiguration);

        void Out(const Channel::Pointer &apChannel, const Log &apLog) const override;

        void Terminate() const override;
    };
}