#include "catch.hpp"
#include "Hill.hpp"
#include "Matrix.hpp"

TEST_CASE("default constructor", "[Hill]")
{
    INFO("Hint: default constructor (linear getE/D() must work)");
    Hill LS;
    Matrix E(std::vector<int>{2, 4, 3, 5}, 2, 2);
    Matrix D(std::vector<int>{12, 2, 16, 28}, 2, 2);
    REQUIRE(LS.getE().equal(E));
    REQUIRE(LS.getD().equal(D));


}
