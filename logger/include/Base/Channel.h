//
// Created by zeyad-osama on 25/07/2020.
//

#pragma once

#include <Base/Log.h>
#include <Utils/DataTypes/SharedPointer.h>
#include <Utils/DataTypes/Severity.h>

#include <map>
#include <string>

namespace Log {
    /**
     * @brief   Channel shared by Logger objects using the same name
     * <br>
     * A Channel is the underlying object used by one or many Logger objects to
     * associate a named prefix and an Output SEVERITY.
     * <br>
     * Sharing a same Channel between multiple Logger enable changing the
     * Level of many Logger objects at once.
     */
    class Channel {
    public:
        typedef shared_ptr<Channel> Pointer;
        typedef std::map<const char *, Pointer> Map;

        Channel(const char *aName, SEVERITY aSeverity) :
                mName(aName),
                mSeverity(aSeverity) {}

        ~Channel() = default;

        inline const char *GetName() const {
            return mName;
        }

        inline void SetSeverity(SEVERITY aSeverity) {
            mSeverity = aSeverity;
        }

        inline SEVERITY GetSeverity() const {
            return mSeverity;
        }

    private:
        const char *mName;
        SEVERITY mSeverity;
    };
}