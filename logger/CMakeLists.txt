# CLogger Library CMakeLists.txt

include_directories(include)
add_library(
        LoggerCPP
        SHARED

        include/Base/Channel.h
        include/Base/Configuration.h
        include/Base/Log.h
        include/Base/Logger.h
        include/Base/Manager.h
        include/Output/Stream/OutputConsole.h
        include/Output/Stream/OutputFile.h
        include/Output/Stream/OutputConsole.h
        include/Output/Stream/OutputFile.h
        include/Utils/Options/OutputStream.h
        include/Utils/Options/Options.h
        include/Utils/DataTypes/Severity.h
        include/Utils/DataTypes/SharedPointer.h
        include/Utils/LibVars/Definitions.h
        include/Utils/LibVars/Extension.h
        include/Utils/ConsoleColors.h
        include/Utils/Timestamp.h
        include/Utils/Utils.h
        include/LoggerCPP.h

        src/Base/Configuration.cpp
        src/Base/Log.cpp
        src/Base/Manager.cpp
        src/Output/Stream/OutputConsole.cpp
        src/Output/Stream/OutputFile.cpp
        src/Utils/Timestamp.cpp
        src/Utils/Utils.cpp
)