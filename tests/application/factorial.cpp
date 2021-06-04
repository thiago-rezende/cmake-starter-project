#include <doctest/doctest.h>

uint32_t factorial(uint32_t number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("Testing the factorial function")
{
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}
