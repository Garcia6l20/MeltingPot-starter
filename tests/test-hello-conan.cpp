#define CATCH_CONFIG_MAIN // This tells the catch header to generate a main
#include <catch2/catch.hpp>

#include <hello-conan/hello-conan.hpp>

using namespace std::string_literals;

TEST_CASE("HelloConan greetings test") {
  SECTION("Greeting someone should be ok") {
    REQUIRE(HelloConan::greet({"fake_exe_name", "world"}) == 0);
  }
  SECTION("Greeting no one should fail") {
    REQUIRE(HelloConan::greet({"fake_exe_name"}) == -1);
  }
}
