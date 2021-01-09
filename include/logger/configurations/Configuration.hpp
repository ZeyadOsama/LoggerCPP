//
// Created by zeyad-osama on 25/07/2020.
//

#ifndef LOGGER_CONFIGURATIONS_CONFIGURATION_HPP
#define LOGGER_CONFIGURATIONS_CONFIGURATION_HPP

#include <logger/common/datatypes/SharedPointer.hpp>

#include <string>
#include <vector>
#include <map>

namespace logger {
    namespace configurations {

        /**
         * @brief   Configuration for an output object
         * <br>
         * A Configuration object is an associative container of strings key and values,
         * with easy to use helper manipulation functions.
         */
        class Configuration {
        public:
            typedef shared_ptr<Configuration> Pointer;
            typedef std::vector<Pointer> ConfigurationList;
            typedef std::map<const char *, const char *> Values;

        public:
            explicit Configuration(const char *OutputStream) : mName(OutputStream) {}

            ~Configuration() = default;

            inline const char *GetName() const {
                return mName;
            }

            inline const Values &GetValues() const {
                return mValue;
            }

            inline void SetValue(const char *key, const char *val) {
                mValue[key] = val;
            }

            std::string Get(const char *key, const char *DefaultValue) const;

            long Get(const char *key, long DefaultValue) const;

            static void RegisterOutput
                    (ConfigurationList &apConfigurationList, const char *OutputSteam);

            static void RegisterOption
                    (ConfigurationList &apConfigurationList, const char *key, const char *val);

        private:
            const char *mName;
            Values mValue;
        };
    } //namespace configurations
} //namespace logger


#endif //LOGGER_CONFIGURATIONS_CONFIGURATION_HPP