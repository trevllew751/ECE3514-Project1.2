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

TEST_CASE("parameterized constructor (Matrix, bool)", "[Hill]") {
    Matrix E(std::vector<int>{2, 3, 2, 1, 2, 1, 1, 1, 2}, 3, 3);
    Matrix D(std::vector<int>{3, 25, 28, 28, 2, 0, 28, 1, 1}, 3, 3);
    Hill LS(E, true);
    REQUIRE(LS.getE().equal(E));
    REQUIRE(LS.getD().equal(D));
    Hill LS1(D, false);
    REQUIRE(LS1.getE().equal(E));
    REQUIRE(LS1.getD().equal(D));
    Matrix zero(std::vector<int>(), 0, 0);
    Matrix A(std::vector<int>(9, 1), 3, 3);
    Hill hill(A, true);
    REQUIRE(hill.getE().equal(zero));
    REQUIRE(hill.getD().equal(zero));
}

TEST_CASE("parameterized constructor (Matrix, Matrix)", "[Hill]") {
    Matrix E(std::vector<int>{2, 3, 2, 1, 2, 1, 1, 1, 2}, 3, 3);
    Matrix D(std::vector<int>{3, 25, 28, 28, 2, 0, 28, 1, 1}, 3, 3);
    Hill LS(E, D);
    REQUIRE(LS.getE().equal(E));
    REQUIRE(LS.getD().equal(D));
    Hill LS1(D, E);
    REQUIRE(LS1.getE().equal(D));
    REQUIRE(LS1.getD().equal(E));
}

TEST_CASE("setE", "[Hill]") {
    Hill LS;
    Matrix E(std::vector<int>{2, 4, 3, 5}, 2, 2);
    Matrix D(std::vector<int>{12, 2, 16, 28}, 2, 2);
    REQUIRE(LS.setE(E));
    Matrix F(std::vector<int>(6, 1), 3, 2);
    REQUIRE_FALSE(LS.setE(F));
}

TEST_CASE("setD", "[Hill]") {
    Hill LS;
    Matrix E(std::vector<int>{2, 4, 3, 5}, 2, 2);
    Matrix D(std::vector<int>{12, 2, 16, 28}, 2, 2);
    REQUIRE(LS.setD(E));
    Matrix F(std::vector<int>(6, 1), 3, 2);
    REQUIRE_FALSE(LS.setD(F));
}

TEST_CASE("encrypt(string)", "[Hill]") {
    Matrix E(std::vector<int>{17, 23, 11, 5, 9, 2, 20, 3, 12}, 3, 3);
    Hill LS (E, true);
    REQUIRE(LS.encrypt("WANT HELP.") == "ZXVXOBREOTLM");
    Matrix A(std::vector<int>(9, 1), 3, 3);
    Hill hill(A, true);
    REQUIRE(hill.encrypt("Hello").empty());
}

TEST_CASE("encrypt(string, Matrix)", "[Hill]") {
    Matrix zero(std::vector<int>(), 0, 0);
    Matrix E(std::vector<int>{17, 23, 11, 5, 9, 2, 20, 3, 12}, 3, 3);
    Hill LS;
    REQUIRE(LS.encrypt("WANT HELP.", E) == "ZXVXOBREOTLM");
}