//
// Created by zeyad-osama on 25/07/2020.
//

#include <Base/Manager.h>
#include <Output/Stream/OutputConsole.h>
#include <Output/Stream/OutputFile.h>
#include <Utils/Utils.h>

#include <string>
#include <sys/stat.h>

using namespace std;

namespace Log {

    Channel::Map Manager::mChannelMap;
    Output::Vector Manager::mOutputList;
    SEVERITY Manager::mDefaultSeverity = DEBUG;

    void Manager::Configure(const Configuration::ConfigurationList &apConfigurationList) {
        string sOutputConsole = typeid(OutputConsole).name();
        string sOutputFile = typeid(OutputFile).name();

        Configuration::ConfigurationList::const_iterator it;
        for (it = apConfigurationList.begin(); it != apConfigurationList.end(); ++it) {
            Output::Pointer outputPtr;
            const string &config_name = (*it)->GetName();

            if (string::npos != sOutputConsole.find(config_name)) {
                outputPtr.reset(new OutputConsole(*it));
            } else if (string::npos != sOutputFile.find(config_name)) {
                mkdir(STR_TO_CHR(LOG_OUT_DIR), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
                outputPtr.reset(new OutputFile(*it));
            }
            mOutputList.push_back(outputPtr);
        }
    }

    void Manager::Terminate() {
        Output::Vector::iterator it;
        for (it = mOutputList.begin(); it != mOutputList.end(); ++it) {
            (*it)->Terminate();
        }
        mOutputList.clear();
    }

    void Manager::Out(const Channel::Pointer &apChannel, const Log &apLog) {
        Output::Vector::iterator it;
        for (it = mOutputList.begin(); it != mOutputList.end(); ++it) {
            (*it)->Out(apChannel, apLog);
        }
    }

    Channel::Pointer Manager::Get(const char *ChannelName) {
        Channel::Pointer ChannelPtr;
        auto iChannelPtr = mChannelMap.find(ChannelName);

        if (mChannelMap.end() != iChannelPtr) {
            ChannelPtr = iChannelPtr->second;
        } else {
            ChannelPtr.reset(new Channel(ChannelName, mDefaultSeverity));
            mChannelMap[ChannelName] = ChannelPtr;
        }
        return ChannelPtr;
    }

    Configuration::Pointer Manager::GetChannelConfiguration() {
        Configuration::Pointer ConfigPtr(new Configuration("ChannelConfig"));

        Channel::Map::const_iterator it;
        for (it = mChannelMap.begin(); it != mChannelMap.end(); ++it) {
            ConfigPtr->SetValue(it->first, to_string(it->second->GetSeverity()));
        }
        return ConfigPtr;
    }

    void Manager::GetChannelConfiguration(const Configuration::Pointer &apConfiguration) {
        const Configuration::Values &config_values = apConfiguration->GetValues();

        Configuration::Values::const_iterator it;
        for (it = config_values.begin(); it != config_values.end(); ++it) {
            Manager::Get(it->first)->SetSeverity(to_level(it->second));
        }
    }

    void Manager::SetDefaultSeverity(SEVERITY aSeverity) {
        mDefaultSeverity = aSeverity;
    }
}