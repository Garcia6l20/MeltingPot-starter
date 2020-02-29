#include <lyra/lyra.hpp>
#include <fmt/format.h>
#include <iostream>

int main(int argc, char** argv) {
  std::string who;
  auto cli = lyra::cli_parser() |
    lyra::arg(who, "who")("Who shall I greet ?");

  auto result = cli.parse({argc, argv});
  if (!result | who.empty()) {
    if (!who.empty())
      fmt::print("Error: {}\n", result.errorMessage());
    std::cerr << cli;
    return -1;
  }
  fmt::print("Greetings {} !\n", who);
  return 0;
}
