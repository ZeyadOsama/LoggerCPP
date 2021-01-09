//
// Created by zeyad-osama on 25/07/2020.
//

#ifndef LOGGER_OUTPUT_STREAM_OUTPUT_FILE_HPP
#define LOGGER_OUTPUT_STREAM_OUTPUT_FILE_HPP

#include <logger/output/interface/Output.hpp>
#include <logger/configurations/Configuration.hpp>

#include <string>

namespace logger {
    namespace output {

        class OutputFile : public Output {
        public:

            explicit OutputFile(const configurations::Configuration::Pointer &apConfiguration);

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
    } //namespace output
} //namespace logger

#endif //LOGGER_OUTPUT_STREAM_OUTPUT_FILE_HPP