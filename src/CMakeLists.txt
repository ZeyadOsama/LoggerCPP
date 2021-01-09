set(SOURCES

        ${CMAKE_CURRENT_SOURCE_DIR}/configurations/Configuration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/common/dataunits/Log.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/configurations/Manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/output/concrete/OutputConsole.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/output/concrete/OutputFile.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/Timestamp.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/Utils.cpp
        )

add_library(LoggerCPP
        STATIC
        ${SOURCES}
        )