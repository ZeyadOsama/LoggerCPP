# LoggerCPP

[![CI Actions Status](https://github.com/ZeyadOsama/LoggerCPP/workflows/CI/badge.svg)](https://github.com/ZeyadOsama/LoggerCPP/actions)
<img src="https://img.shields.io/pypi/status/Django.svg" alt="stable"/>
<img src="https://img.shields.io/badge/contributions-welcome-orange.svg" alt="contributions-welcome-orange"/>

## About
C++ Logging System.

## Usage
In your  **```CMakeLists.txt```** file add these lines

```cmake
add_subdirectory(logger)
include_directories(logger/include)
```

Then add this header in the file you'd like to have your parser at
```c++
#include <logger/LoggerCPP.h>

using namespace logger;
```

### Configurations
##### Configuration List
You should create firstly a **```ConfigurationList```** to store all your configurations.
```c++
// ConfigurationList instance
Configuration::ConfigurationList cl;
```

#### Output
You can find all output streams at at  **```OUTPUT_STREAM::<output_stream>```**
```c++
OUTPUT_STREAM::CONSOLE
OUTPUT_STREAM::FILE
```

```c++
// Configure the output objects
Configuration::RegisterOutput(cl, "<output-concrete>");
```
```c++
// Example
Configuration::RegisterOutput(cl, OUTPUT_STREAM::CONSOLE);
```

#### Option
You can find all options at  **```OPTIONS::<option>```**
```c++
OPTION::FILE_NAME
OPTION::MAX_FILES
```

```c++
// Configure the Option objects
Configuration::RegisterOption(cl, "<option>", "value");
```
```c++
// Example
Configuration::RegisterOption(cl, OPTION::FILE_NAME, "log.txt");
```

### Manager

##### Setting Default Severity
```c++
// Set Default Severity
Manager::SetDefaultSeverity(DEBUG);
```

##### Changing Severity For a Channel
```c++
// Changing Severity 
Manager::Get("<channel-name>")->SetSeverity(NOTE);
```
**```<channel-name>```** is the name you pass as a parameter for the **```Logger```** object.
```c++
Logger l("<channel-name>");
```

##### Terminating LoggerCPP
```c++
// Terminating
Manager::Terminate();
```

### Logger Object
##### Creating Logger Object
```c++
// Create Logger object
Logger l("<channel-name>");
```

##### Using Logger Object
```c++
l.notice() << "<message>";
l.debug() << "<message>";
l.crtic() << "<message>";
l.error() << "<message>";
l.info() << "<message>";
l.warn() << "<message>";
```
After **```<logger-object>.<function> <<```** you can enter anything normally as using **```std::cout <<```**

## Output
LoggerCPP outputs a folder named **```log```** containing the latest **```MAX_FILES```** number log files. You can change **```MAX_FILES```** default value which is **```MAX_FILES```** to any other value using:
```c++
// Example
Configuration::RegisterOption(cl, OPTION::MAX_FILES, "<MAX_FILES>");
```

Files are named as **```<current-timestamp>.log```**
```text
2020-08-17 15:55:35.584.log
```
**N.B.** **```.log```** is the default extension for LoggerCPP.

You can change **```filename```** default value to any other value using:
```c++
// Example
Configuration::RegisterOption(cl, OPTION::FILE_NAME, "<filename>.<extension>");
```
#### Example Output File
```text
2020-08-17 15:55:35.585  Main.Example DBUG This is a debug message.
2020-08-17 15:55:35.585  Main.Example INFO This is an info message.
2020-08-17 15:55:35.585  Main.Example NOTE This is a note message.
2020-08-17 15:55:35.585  Main.Example WARN This is a warning message.
2020-08-17 15:55:35.585  Main.Example EROR This is an error message.
2020-08-17 15:55:35.585  Main.Example CRIT This is a critical message.
```

## Versioning
When installing LoggerCPP, require it's version. For us, this is what ```major.minor.patch``` means:

- ```major``` - **MAJOR breaking changes**; includes major new features, major changes in how the whole system works, and complete rewrites; it allows us to _considerably_ improve the product, and add features that were previously impossible.
- ```minor``` - **MINOR breaking changes**; it allows us to add big new features.
- ```patch``` - **NO breaking changes**; includes bug fixes and non-breaking new features.

## Change Log

For all-time versions, please see the [CHANGELOG](CHANGELOG.rst) file.


## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details

