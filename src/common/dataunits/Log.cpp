//
// Created by zeyad-osama on 25/07/2020.
//

#include <logger/common/dataunits/Log.hpp>
#include <logger/logger/Logger.hpp>

using namespace std;

using namespace logger;

Log::Log(const Logger &aLogger, SEVERITY aSeverity)
        : mLogger(aLogger),
          mSeverity(aSeverity),
          mStream(nullptr) {
    // Construct a concrete only if the severity of the logger is above its Logger logger::Level
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
