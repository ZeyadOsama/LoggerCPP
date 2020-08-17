//
// Created by zeyad-osama on 25/07/2020.
//

#pragma once

#include <Base/Log.h>
#include <Base/Channel.h>
#include <Base/Configuration.h>
#include <Output/Output.h>
#include <Utils/DataTypes/Severity.h>

namespace Log {

    /**
    * @brief   The static class that manage the registered channels and outputs
    * <br>
    * The Manager keeps a map of all the named Channel objects
    * and share them on demand by new Logger objects created with the same name.
    * <br>
    * Thus the Manager is able to change the Severity Level of selected Channel object,
    * impacting all the Logger objects using it.
    * <br>
    * The Manager also keeps a list of all configured Output object to Output the Log objects.
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
        static Output::Vector mOutputList;
        static SEVERITY mDefaultSeverity;
    };
}