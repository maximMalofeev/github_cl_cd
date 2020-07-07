#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Simple test"){
  REQUIRE(1 != 2);
}
