cmake_minimum_required(VERSION 3.11)
if(NOT EXISTS "${CMAKE_BINARY_DIR}/MeltingPot.cmake")
  message(STATUS "Downloading MeltingPot.cmake from https://github.com/Garcia6l20/MeltingPot")
  file(DOWNLOAD "https://raw.githubusercontent.com/Garcia6l20/MeltingPot/v0.1.x/dist/MeltingPot.cmake" "${CMAKE_BINARY_DIR}/MeltingPot.cmake")
endif()
include(${CMAKE_BINARY_DIR}/MeltingPot.cmake)

project(MeltProject)

set(CMAKE_CXX_STANDARD 17)

conan_requires(
    fmt/6.1.0
    lyra/1.3.0
  BUILD outdated
  OPTIONS
    fmt:header_only=True
)

melt_executable(${PROJECT_NAME}
  SOURCES src/main.cpp
  LIBRARIES
    CONAN_PKG::lyra
    CONAN_PKG::fmt
)
