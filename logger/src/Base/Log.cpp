//
// Created by zeyad-osama on 25/07/2020.
//

#include <Base/Log.h>
#include <Base/Logger.h>

using namespace std;

namespace Log {

    Log::Log(const Logger &aLogger, SEVERITY aSeverity) :
            mLogger(aLogger),
            mSeverity(aSeverity),
            mStream(nullptr) {
        // Construct a Stream only if the severity of the Log is above its Logger Log::Level
        if (aSeverity >= aLogger.GetSeverity()) {
            mStream = new(ostringstream);
        }
    }

    Log::~Log() {
        if (nullptr != mStream) {
            mTimestamp.Generate();
            mLogger.Out(*this);

            delete mStream;
            mStream = nullptr;
        }
    }
}