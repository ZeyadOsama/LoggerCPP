//
// Created by zeyad-osama on 25/07/2020.
//

#ifndef LOGGER_OUTPUT_STREAM_OUTPUT_CONSOLE_HPP
#define LOGGER_OUTPUT_STREAM_OUTPUT_CONSOLE_HPP

#include <logger/output/interface/Output.hpp>
#include <logger/configurations/Configuration.hpp>

namespace logger {
    namespace output {

        class OutputConsole : public Output {
        public:
            explicit OutputConsole(const configurations::Configuration::Pointer &apConfiguration);

            void Out(const Channel::Pointer &apChannel, const Log &apLog) const override;

            void Terminate() const override;
        };
    } //namespace output
} //namespace logger

#endif //LOGGER_OUTPUT_STREAM_OUTPUT_CONSOLE_HPP