cmake_minimum_required(VERSION 3.16.3)
project(FLCounter)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/StrategyFactory.cpp
    src/AllStrategy.cpp
    src/RecursiveAllStrategy.cpp
    src/ExtensionStrategy.cpp
    src/RecursiveExtensionStrategy.cpp
    src/PathIterator.cpp
    src/DataProcessor.cpp
)

enable_testing()
add_library(FLCounter_lib STATIC ${SOURCES})

target_include_directories(FLCounter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(FLCounter src/main.cpp)
target_link_libraries(FLCounter FLCounter_lib)

#Set your gtest directory here
set(GTEST_DIR "/usr/local/lib")

add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES
    IMPORTED_LOCATION ${GTEST_DIR}/libgtest.a
    INTERFACE_INCLUDE_DIRECTORIES ${GTEST_DIR}
)

add_executable(runTests 
../test/runTests.cpp)

target_link_libraries(runTests gtest pthread FLCounter_lib)

include(GoogleTest)
gtest_discover_tests(runTests)