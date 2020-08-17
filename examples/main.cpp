#include <iostream>

#include <LoggerCPP.h>

using namespace Log;

class Test {
private:
    Logger mLogger;

public:

    Test() :
            mLogger("Main.Test") {}

    void ConstTest() const {
        mLogger.debug() << "log within a const method";
    }
};

int main() {
    // Configure the default severity Level of new Channel objects
#ifndef NDEBUG
    Manager::SetDefaultSeverity(DEBUG);
#else
    Manager::setDefaultLevel(eNotice);
#endif

    dout << "WTF" << std::endl;

    // Configure the Output objects
    Configuration::ConfigurationList cl;
    Configuration::RegisterOutput(cl, OUTPUT_STREAM::CONSOLE);
    Configuration::RegisterOutput(cl, OUTPUT_STREAM::FILE);
    Configuration::RegisterOption(cl, OPTION::FILE_NAME, "log.txt");

    // Create a Logger object, using a "Main.Example" Channel
    Logger l1("Main.Example");
    l1.warn() << "NO logs before configure()";

    try {
        // Configure the Log Manager (create the Output objects)
        Manager::Configure(cl);
    }
    catch (std::exception &e) {
        std::cerr << e.what();
    }

    // Test outputs of various kind of variables, and some common Stream manipulations.
    std::string str("string");
    unsigned int ui = 123;
    double dbl = -0.023f;
    l1.debug() << "Variables ; '" << str << "', '" << ui << "', '" << dbl << "'";
    l1.debug() << "Hexa = " << std::hex << 0x75af0 << " test";
    l1.debug() << "Deci = " << std::right << std::setfill('0') << std::setw(8) << 76035 << " test";
    l1.debug() << "sizeof(logger)=" << sizeof(l1);

    // Test outputs of various severity Level
    l1.debug() << "Debug.";
    l1.info() << "Info.";
    l1.notice() << "Notice.";
    l1.warn() << "Warning.";
    l1.error() << "Error.";
    l1.critic() << "Critic.";

    // Modify the Output Level of the underlying Channel, and test various severity Level again
    l1.SetSeverity(WARN);
    l1.debug() << "NO Debug.";     // NO more debug logs
    l1.info() << "NO Info.";      // NO more info logs
    l1.notice() << "NO Notice.";    // NO more notice logs
    l1.warn() << "Warning.";
    l1.error() << "Error.";
    l1.critic() << "Critic.";

    // Reset Level of the "Main.example" channel by its name
    Manager::Get("Main.Example")->SetSeverity(DEBUG);

    // Create other loggers, sharing the "Main.Example" Channel, and creating a new one
    Logger l2("Main.Foo");
    Logger l3("Main.Bar");
    l1.debug() << "First logger to the Channel";
    l2.debug() << "Second logger to the Channel";
    l3.debug() << "Third logger, other Channel";
    // Modify the Level of the "Main.example" channel by its name
    Manager::Get("Main.Example")->SetSeverity(INFO);
    l1.debug() << "first logger inhibited";         // NO more debug logs for this logger
    l2.debug() << "second logger also disabled";   // NO more debug logs (sharing the same underlying channel)
    l3.debug() << "third logger still active";
    // Reset the Level of the "Main.example" channel by its name
    Manager::Get("Main.Example")->SetSeverity(DEBUG);
    l1.debug() << "first logger re-activated";
    l2.debug() << "second logger also re-activated";
    l3.debug() << "third logger always active";

    // Create an object using a Logger as member variable
    Test t;
    t.ConstTest();

    // Show how to get the current Channel configuration (to save it to a file, for instance)
    Manager::Get("Main.Baz")->SetSeverity(NOTE);
    Configuration::Pointer ChannelConfigPtr = Manager::GetChannelConfiguration();
    // Show how to set the current Channel configuration (restored from a file, for instance)
    Manager::GetChannelConfiguration(ChannelConfigPtr);

    // Terminate the Log Manager (destroy the Output objects)
    Manager::Terminate();
    l1.warn() << "NO more logs after terminate()";

    return 0;
}