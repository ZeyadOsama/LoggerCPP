//
// Created by zeyad-osama on 25/07/2020.
//

#pragma once

#include <Output/Output.h>
#include <Base/Configuration.h>

#include <string>

namespace Log {

    class OutputFile : public Output {
    public:

        explicit OutputFile(const Configuration::Pointer &apConfiguration);

        ~OutputFile() override;

        void Out(const Channel::Pointer &apChannel, const Log &apLog) const override;

        void Terminate() const override;

    private:
        void Open() const;

        void Close() const;

    private:
        mutable FILE *mFile;

        std::string mFileName;
    };
}