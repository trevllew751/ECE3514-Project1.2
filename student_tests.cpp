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
    Matrix Zero(std::vector<int>(), 0, 0);
    Matrix one(std::vector<int>{1}, 1, 1);
    REQUIRE_FALSE(LS.setE(F));
    REQUIRE_FALSE(LS.setE(Zero));
    REQUIRE_FALSE(LS.setE(one));
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
    Matrix E(std::vector<int>{13, 11, 24, 16, 23, 13, 1, 1, 5, 11, 21, 5, 8, 19, 9, 10, 5, 11, 26, 25, 12, 19, 8, 27,
                              18}, 5, 5);
    Matrix D(std::vector<int>{18, 25, 23, 10, 4, 17, 9, 24, 18, 26, 16, 26, 25, 22, 6, 27, 2, 18, 11, 27, 3, 6, 5, 27,
                              17}, 5, 5);
    Hill LS(E, true);
    REQUIRE(LS.getD().equal(D));
    std::string P = "GDQHCEBTWXHZRAJPSMXE YJRICPXW?JLEJQPEDLYFODZWQLOZ.OP.QWTNGRFFYDSMRVIBYKTZH YWTPLXRW WYOZJFOAXHTXTSGN";
    std::string C = "ZTUNEDUI ULKYU.C FRWAFEFVBVJSERPWNHM FEVMSABMSGEP.NOMFJS.TQSKG?F DNAOUDJGPJD?RFBSKLSJJVBW G?YWCJBPHI";
    REQUIRE(LS.encrypt(P) == C);
    Matrix A(std::vector<int>(9, 1), 3, 3);
    Hill hill(A, true);
    REQUIRE(hill.encrypt("Hello").empty());
    REQUIRE(LS.encrypt("Invalid characters: 32^%#").empty());
}

TEST_CASE("encrypt(string, Matrix)", "[Hill]") {
    Matrix E(std::vector<int>{17, 23, 11, 5, 9, 2, 20, 3, 12}, 3, 3);
    Hill LS;
    REQUIRE(LS.encrypt("WANT HELP.", E) == "ZXVXOBREOLGL");
    REQUIRE(LS.encrypt("Invalid characters: 32^%#", E).empty());
}

TEST_CASE("decrypt(string)", "[Hill]") {
    Matrix E(std::vector<int>{13, 11, 24, 16, 23, 13, 1, 1, 5, 11, 21, 5, 8, 19, 9, 10, 5, 11, 26, 25, 12, 19, 8, 27,
                              18}, 5, 5);
    Matrix D(std::vector<int>{18, 25, 23, 10, 4, 17, 9, 24, 18, 26, 16, 26, 25, 22, 6, 27, 2, 18, 11, 27, 3, 6, 5, 27,
                              17}, 5, 5);
    Hill LS(D, false);
    REQUIRE(LS.getE().equal(E));
    std::string P = "GDQHCEBTWXHZRAJPSMXE YJRICPXW?JLEJQPEDLYFODZWQLOZ.OP.QWTNGRFFYDSMRVIBYKTZH YWTPLXRW WYOZJFOAXHTXTSGN";
    std::string C = "ZTUNEDUI ULKYU.C FRWAFEFVBVJSERPWNHM FEVMSABMSGEP.NOMFJS.TQSKG?F DNAOUDJGPJD?RFBSKLSJJVBW G?YWCJBPHI";
    REQUIRE(LS.decrypt(C) == P);
    REQUIRE(LS.decrypt("Invalid characters: 32^%#").empty());
}

TEST_CASE("decrypt(string, Matrix)", "[Hill]") {
    Matrix D(std::vector<int>{16, 25, 15, 27, 10, 5, 27, 9, 27}, 3, 3);
    Hill LS;
    REQUIRE(LS.decrypt("ZXVXOBREOTLM", D) == "WANT HELP...");
    REQUIRE(LS.decrypt("Invalid characters: 32^%#", D).empty());
}