set(test_source 
    unitTest.cpp)

find_package(GTest REQUIRED)

add_executable(unitTest ${test_source})

target_link_libraries(unitTest configparser)
target_link_libraries(unitTest GTest::GTest GTest::Main)

add_test(NAME unitTest
         COMMAND unitTest
)
