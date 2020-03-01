#pragma once

#include <hello-conan/hello-conan-export.hpp>

#include <initializer_list>
#include <string>

class HELLO_CONAN_EXPORT HelloConan {
public:
  static int greet(std::initializer_list<std::string>);
};
