# add the example executable, linked with the LoggerCPP library
add_executable(LoggerCPP_Example main.cpp)
target_link_libraries(LoggerCPP_Example LoggerCPP ${SYSTEM_LIBRARIES})