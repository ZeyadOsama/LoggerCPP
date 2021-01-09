//
// Created by zeyad-osama on 25/07/2020.
//

#ifndef LOGGER_CONFIGURATIONS_MANGER_HPP
#define LOGGER_CONFIGURATIONS_MANGER_HPP

#include <logger/common/dataunits/Log.hpp>
#include <logger/common/Channel.hpp>
#include <logger/configurations/Configuration.hpp>
#include <logger/output/interface/Output.hpp>
#include <logger/common/datatypes/Severity.hpp>

namespace logger {
    namespace configurations {

        /**
        * @brief   The static class that manage the registered channels and outputs
        * <br>
        * The Manager keeps a map of all the named Channel objects
        * and share them on demand by new Logger objects created with the same name.
        * <br>
        * Thus the Manager is able to change the Severity Level of selected Channel object,
        * impacting all the Logger objects using it.
        * <br>
        * The Manager also keeps a list of all configured output object to output the logger objects.
        */
        class Manager {
        public:
            static void Configure(const Configuration::ConfigurationList &apConfigurationList);

            static void Terminate();

            static void Out(const Channel::Pointer &apChannel, const Log &apLog);

            static Channel::Pointer Get(const char *ChannelName);

            static Configuration::Pointer GetChannelConfiguration();

            static void GetChannelConfiguration(const Configuration::Pointer &apConfiguration);

            static void SetDefaultSeverity(SEVERITY aSeverity);

        private:
            static Channel::Map mChannelMap;
            static output::Output::Vector mOutputList;
            static SEVERITY mDefaultSeverity;
        };
    } //namespace configurations
} //namespace logger


#endif //LOGGER_CONFIGURATIONS_MANGER_HPP