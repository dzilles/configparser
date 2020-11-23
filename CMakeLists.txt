cmake_minimum_required(VERSION 3.8.2)
project (configparser)

set(configparser_source 
    src/configparser.cpp)

add_library(configparser STATIC ${configparser_source})
set_target_properties(configparser PROPERTIES PUBLIC_HEADER "include/configparser.hpp")

install(TARGETS configparser ARCHIVE DESTINATION ${LIBDIR}
                             LIBRARY DESTINATION ${LIBDIR}
                             PUBLIC_HEADER DESTINATION ${INCLUDEDIR})

target_include_directories(configparser PUBLIC include)

enable_testing()
add_subdirectory(test)
