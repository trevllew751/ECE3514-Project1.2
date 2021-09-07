//your code here.
#include "Hill.hpp"

Hill::Hill() {

}

Hill::Hill(const Matrix &K, bool encryption) {

}

Hill::Hill(const Matrix &E, const Matrix &D) {

}

Matrix Hill::getE() const {
    return Matrix();
}

Matrix Hill::getD() const {
    return Matrix();
}

bool Hill::setE(const Matrix &E) {
    return false;
}

bool Hill::setD(const Matrix &D) {
    return false;
}

std::string Hill::encrypt(const std::string &P) const {
    return std::string();
}

std::string Hill::encrypt(const std::string &P, const Matrix &E) {
    return std::string();
}

std::string Hill::decrypt(const std::string &C) const {
    return std::string();
}

std::string Hill::decrypt(const std::string &C, const Matrix &D) {
    return std::string();
}

bool Hill::kpa(const std::vector<std::string> &P, const std::vector<std::string> &C, unsigned int n) {
    return false;
}

Matrix Hill::l2num(const std::string &s, unsigned int n) {
    return Matrix();
}

std::string Hill::n2let(const Matrix &A) {
    return std::string();
}

Matrix Hill::inv_mod(Matrix A) {
    return Matrix();
}

unsigned int Hill::mod(int a, int b) {
    return 0;
}

void Hill::row_mult(Matrix &A, unsigned int i, unsigned int j, unsigned int k, unsigned int c) {

}

void
Hill::row_diff(Matrix &A, unsigned int i, unsigned int j, unsigned int k, Matrix &B, unsigned int l, unsigned int c) {

}

