//
// Created by zeyad-osama on 25/07/2020.
//

#ifndef LOGGER_OUTPUT_OUTPUT_HPP
#define LOGGER_OUTPUT_OUTPUT_HPP

#include <logger/common/Channel.hpp>
#include <logger/common/datatypes/SharedPointer.hpp>

#include <vector>
#include <typeinfo>

namespace logger {
    namespace output {

        /**
         * @brief output Interface
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
    } //namespace output
} //namespace logger

#endif //LOGGER_OUTPUT_OUTPUT_HPP