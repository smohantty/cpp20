cmake_minimum_required(VERSION 3.20)

# Set the project name and version
project(cpp20 VERSION 1.0 LANGUAGES CXX)

# Enable C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directories for build files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Fetch third-party libraries if you need to build as a static library and link against it.
#add_subdirectory(external/stdexec)
#target_link_libraries(cpp20test PRIVATE STDEXEC::stdexec)

# Add include directories (for header-only library)
include_directories(${PROJECT_SOURCE_DIR}/external/stdexec/include)


# Add the executable target
add_executable(cpp20test src/cpp20test.cpp)

