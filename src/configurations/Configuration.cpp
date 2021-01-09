//
// Created by zeyad-osama on 25/07/2020.
//

#include <logger/configurations/Configuration.hpp>

using namespace std;

using namespace logger::configurations;

string Configuration::Get(const char *key, const char *DefaultValue) const {
    string val;
    auto it = mValue.find(key);
    if (mValue.end() != it) {
        val = it->second;
    } else {
        val = DefaultValue;
    }
    return val;
}

long Configuration::Get(const char *key, long DefaultValue) const {
    long val;
    auto it = mValue.find(key);
    if (mValue.end() != it) {
        string::size_type size;
        val = stol(it->second, &size);
    } else {
        val = DefaultValue;
    }
    return val;
}

void Configuration::RegisterOutput(ConfigurationList &apConfigurationList, const char *OutputStream) {
    Configuration::Pointer configPtr(new Configuration(OutputStream));
    apConfigurationList.push_back(configPtr);
}

void Configuration::RegisterOption
        (ConfigurationList &apConfigurationList, const char *key, const char *val) {
    (*apConfigurationList.back()).SetValue(key, val);
}
