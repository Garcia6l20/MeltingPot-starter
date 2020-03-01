cmake_minimum_required(VERSION 3.11)
if(NOT EXISTS "${CMAKE_BINARY_DIR}/MeltingPot.cmake")
  message(STATUS "Downloading MeltingPot.cmake from https://github.com/Garcia6l20/MeltingPot")
  file(DOWNLOAD "https://raw.githubusercontent.com/Garcia6l20/MeltingPot/v0.1.x/dist/MeltingPot.cmake" "${CMAKE_BINARY_DIR}/MeltingPot.cmake")
endif()
include(${CMAKE_BINARY_DIR}/MeltingPot.cmake)

project(hello-conan)

set(CMAKE_CXX_STANDARD 17)

conan_requires(
    fmt/6.1.0
    lyra/1.3.0
  BUILD outdated
  OPTIONS
    fmt:header_only=True
)

melt_library(${PROJECT_NAME}
  # public headers
  HEADERS include/hello-conan/hello-conan.hpp
  # sources and private headers
  SOURCES src/hello-conan.cpp
  # include subfolder and visual studio solution folder
  FOLDER hello-conan
  # linked libraries
  LIBRARIES
    CONAN_PKG::lyra
    CONAN_PKG::fmt
)

conan_package(
  AUTHOR "Your Name <you.email@example.com>"
  LICENSE "MIT"
  URL "https://github.com/Garcia6l20/MeltingPot-starter"
  TOPICS metling-pot example
  DESCRIPTION "Melt packaging sample"
)
