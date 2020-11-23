# configparser
Simple, lightweight C++ configuration/ini file parser for Linux.

## Installation
Inside the main folder execute:

1) `cmake .`
2) `make`
3) `make test`

The following command will install the library in the paths defined by the environment variables `$LIBDIR` and `$INCLUDEDIR`.

4) `make install`

## Usage
A minimal example of a CMake project using the configparser can be found in the [examples folder](examples):
The [CMakeLists.txt](examples/CMakeLists.txt) of a project using the configparser may look like this:
```
set(example_source 
    example.cpp)

# Find the library 
find_library(configparser
    NAME configparser
    HINTS [${LIBDIR} ${INCLUDEDIR}]
)

add_executable(example ${example_source})

# and link to executable defined in example.cpp
target_link_libraries(example configparser)
```
The [example configuration file:](examples/config)
```
; comment 1
[Section1]

example1 = string
example2 = 4
example3 = true
example4 = string1, string2, string3
example5 = true, false, true
example6 = "test!?$§"

; comment 2
[Section2]

example1 = 1, 2, 3, 4
example2 = 5.1, 6.3, 7.5
```
The main function of the example project can be found in the file [example.cpp](examples/example.cpp).
The configuration file entries can be read out as follows:
```
// Include the configparser header
#include "configparser.hpp"

int main() {

  string path = "config.ini";
  // Initialize the parser with a path to the configuration file
  ConfigParser parser = ConfigParser(path);
  
  // Read the configuration file entries:
  //
  // It is possible to read a single entry,
  string c11 = parser.aConfig<string>("Section1", "example1");

  // a whole vector 
  vector<string> c14 = parser.aConfigVec<string>("Section1", "example4");

  // or a single entry of a vector
  double c222 = parser.aConfig<double>("Section2", "example2", 2);
}
```


