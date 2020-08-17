//
// Created by zeyad-osama on 25/07/2020.
//

#pragma once

#include <Utils/DataTypes/SharedPointer.h>

#include <string>
#include <vector>
#include <map>

namespace Log {

    /**
     * @brief   Configuration for an Output object
     * <br>
     * A Configuration object is an associative container of strings key and values,
     * with easy to use helper manipulation functions.
     */
    class Configuration {
    public:
        typedef shared_ptr <Configuration> Pointer;
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
}