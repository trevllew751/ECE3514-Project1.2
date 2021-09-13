//your code here.
#include "Hill.hpp"

Hill::Hill() {
    E = Matrix(std::vector<int>{2, 4, 3, 5}, 2, 2);
    D = inv_mod(E);
}

Hill::Hill(const Matrix &K, bool encryption) {
    Matrix zero(std::vector<int>(), 0, 0);
    if (!inv_mod(K).equal(zero)) {
        if (encryption) {
            this->E = K;
            this->D = inv_mod(K);
        } else {
            this->D = K;
            this->E = inv_mod(K);
        }
    } else {
        this->E = zero;
        this->D = zero;
    }
}

Hill::Hill(const Matrix &E, const Matrix &D) {
    Matrix zero(std::vector<int>(), 0, 0);
    if (!inv_mod(E).equal(D)) {
        this->E = zero;
        this->D = zero;
    } else {
        this->E = E;
        this->D = D;
    }
}

Matrix Hill::getE() const {
    return E;
}

Matrix Hill::getD() const {
    return D;
}

bool Hill::setE(const Matrix &E) {
    Matrix zero(std::vector<int>(), 0, 0);
    if (!inv_mod(E).equal(Matrix(std::vector<int>(), 0, 0))) {
        this->E = E;
        this->D = inv_mod(E);
        return true;
    }
    this->E = zero;
    this->D = zero;
    return false;
}

bool Hill::setD(const Matrix &D) {
    Matrix zero(std::vector<int>(), 0, 0);
    if (!inv_mod(D).equal(Matrix(std::vector<int>(), 0, 0))) {
        this->D = D;
        this->E = inv_mod(D);
        return true;
    }
    this->E = zero;
    this->D = zero;
    return false;
}

std::string Hill::encrypt(const std::string &P) const {
    if (E.equal(Matrix(std::vector<int>(), 0, 0)) || E.size(1) != E.size(2) ||
        inv_mod(E).equal(Matrix(std::vector<int>(), 0, 0))) {
        return "";
    }
    Matrix nums = l2num(P, this->E);
    Matrix encrypted = E.mult(nums);
    for (int i = 0; i < encrypted.size(1) * encrypted.size(2); i++) {
        encrypted.set(i, encrypted.get(i) % 29);
//        std::cout << encrypted.get(i) << " ";
    }
//    std::cout << std::endl;
    return n2let(encrypted);
}

std::string Hill::encrypt(const std::string &P, const Matrix &E) {
    if (E.equal(Matrix(std::vector<int>(), 0, 0)) || E.size(1) != E.size(2) ||
        inv_mod(E).equal(Matrix(std::vector<int>(), 0, 0))) {
        return "";
    }
    Matrix nums = l2num(P, E);
    Matrix encrypted = E.mult(nums);
    for (int i = 0; i < encrypted.size(1) * encrypted.size(2); i++) {
        encrypted.set(i, encrypted.get(i) % 29);
    }
    return n2let(encrypted);
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

Matrix Hill::l2num(const std::string &s, const Matrix &E) const {
    unsigned int n = E.size(1);
    unsigned int numColumns = (s.length() / n) + 1;
    unsigned int length = numColumns * n;
    char back = s.back();
    int fill;
    if (back == ' ') {
        fill = 28;
    } else if (back == '?') {
        fill = 27;
    } else if (back == '.') {
        fill = 26;
    } else {
        fill = back - ASCII_OFFSET;
    }
    std::vector<int> nums(length, fill);
    for (int i = 0; i < s.length(); i++) {
        char c = s.at(i);
        if (c == ' ') {
            nums.at(i) = 28;
        } else if (c == '?') {
            nums.at(i) = 27;
        } else if (c == '.') {
            nums.at(i) = 26;
        } else {
            nums.at(i) = s.at(i) - ASCII_OFFSET;
        }
    }
//    for (int i : nums) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
    return Matrix(nums, n, numColumns);
}

std::string Hill::n2let(const Matrix &A) const {
    std::string result;
    for (int i = 0; i < A.size(1) * A.size(2); i++) {
        result += (char) (A.get(i) + ASCII_OFFSET);
    }
//    for (char &c : result) {
//        std::cout << c << " ";
//    }
    return result;
}

Matrix Hill::inv_mod(Matrix A) const {
    if (A.size(1) != A.size(2)) {
        return Matrix(std::vector<int>(), 0, 0);
    }
    Matrix I(std::vector<int>(A.size(1) * A.size(2)), A.size(1), A.size(2));
    for (int i = 0; i < I.size(1); i++) {
        I.set(i, i, 1);
    }
    Matrix result = I;
    Matrix mat = A;
    for (int i = 0; i < A.size(1); i++) {
        int n = mat.get(i, i);
        if (n == 0) { break; }
        int inverse = ZI29[n - 1];
        row_mult(result, i, 0, result.size(2), inverse);
        row_mult(mat, i, 0, mat.size(2), inverse);
        for (int j = 0; j < A.size(1); j++) {
            if (j != i) {
                row_diff(result, j, 0, result.size(2), result, i, mat.get(j, i));
                row_diff(mat, j, 0, mat.size(2), mat, i, mat.get(j, i));
            }
        }
    }
    if (!mat.equal(I)) {
        return Matrix(std::vector<int>(), 0, 0);
    }
    return result;
}

unsigned int Hill::mod(int a, int b) const {
    int c = a % b;
    return (c < 0) ? c + b : c;
}

void Hill::row_mult(Matrix &A, unsigned int i, unsigned int j, unsigned int k, unsigned int c) const{
    //For row i of Matrix A, multiply columns j through k by c, mod 29
    for (unsigned int col = j; col < k; col++) {
        A.set(i, col, mod(A.get(i, col) * c, 29));
    }
}

void
Hill::row_diff(Matrix &A, unsigned int i, unsigned int j, unsigned int k, Matrix &B, unsigned int l, unsigned int c) const{
    //Multiply columns j through k of row l of Matrix B by c and subtract from columns j through k of row i of Matrix A, mod 29
//    row_mult(B, l, j, k, c);
    Matrix m = B;
    for (unsigned int col = j; col < k; col++) {
        m.set(l, col, m.get(l, col) * c);
    }
    for (unsigned int col = j; col < k; col++) {
        A.set(i, col, mod(A.get(i, col) - m.get(l, col), 29));
    }
}

