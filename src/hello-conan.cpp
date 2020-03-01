#include <hello-conan/hello-conan.hpp>

#include <lyra/lyra.hpp>
#include <fmt/format.h>
#include <iostream>

int HelloConan::greet(std::initializer_list<std::string> args) {
  std::string who;
  auto cli = lyra::cli_parser() |
    lyra::arg(who, "who")("Who shall I greet ?");

  auto result = cli.parse(std::move(args));
  if (!result | who.empty()) {
    if (!who.empty())
      fmt::print("Error: {}\n", result.errorMessage());
    std::cerr << cli;
    return -1;
  }
  fmt::print("Greetings {} !\n", who);
  return 0;
}
