//
// Created by zeyad-osama on 25/07/2020.
//

#include <Output/Stream/OutputConsole.h>
#include <Utils/Utils.h>

namespace Log {

    OutputConsole::OutputConsole(const Configuration::Pointer &apConfiguration) {
        (void) apConfiguration;
    }

    void OutputConsole::Out(const Channel::Pointer &apChannel, const Log &apLog) const {
        const Timestamp &time = apLog.GetTimestamp();

        fprintf(stdout, "\x1B[%02um%.4u-%.2u-%.2u %.2u:%.2u:%.2u.%.3u  %-12s %s %s\x1b[39m\n",
                to_escape_code(apLog.GetLevel()),
                time.year, time.month, time.day, time.hour, time.minute, time.second, time.ms,
                apChannel->GetName(),
                to_string(apLog.GetLevel()),
                (apLog.GetStream()).str().c_str());
        fflush(stdout);
    }

    void OutputConsole::Terminate() const {
    }
}