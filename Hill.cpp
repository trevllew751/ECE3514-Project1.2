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
    if (E.size(1) <= 1 || E.size(2) <= 1) {
        this->E = zero;
        this->D = zero;
        return false;
    }
    Matrix inverse = inv_mod(E);
    if (!inverse.equal(Matrix(std::vector<int>(), 0, 0))) {
        this->E = E;
        for (int i = 0; i < this->E.size(1) * this->E.size(2); i++) {
            this->E.set(i, mod(this->E.get(i), 29));
        }
        this->D = inverse;
        return true;
    }
    this->E = zero;
    this->D = zero;
    return false;
}

bool Hill::setD(const Matrix &D) {
    Matrix zero(std::vector<int>(), 0, 0);
    if (D.size(1) <= 1 || D.size(2) <= 1) {
        this->E = zero;
        this->D = zero;
        return false;
    }
    Matrix inverse = inv_mod(D);
    if (!inverse.equal(Matrix(std::vector<int>(), 0, 0))) {
        this->D = D;
        for (int i = 0; i < this->D.size(1) * this->D.size(2); i++) {
            this->D.set(i, mod(this->D.get(i), 29));
        }
        this->E = inverse;
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
    if (nums.equal(Matrix(std::vector<int>(), 0, 0))) {
        return "";
    }
    Matrix encrypted = E.mult(nums);
    for (int i = 0; i < encrypted.size(1) * encrypted.size(2); i++) {
        encrypted.set(i, encrypted.get(i) % 29);
    }
    return n2let(encrypted);
}

std::string Hill::encrypt(const std::string &P, const Matrix &E) {
    if (E.equal(Matrix(std::vector<int>(), 0, 0)) || E.size(1) != E.size(2) ||
        inv_mod(E).equal(Matrix(std::vector<int>(), 0, 0))) {
        return "";
    }
    Matrix e = E;
    for (int i = 0; i < e.size(1) * e.size(2); i++) {
        e.set(i, mod(e.get(i), 29));
    }
    Matrix nums = l2num(P, e);
    if (nums.equal(Matrix(std::vector<int>(), 0, 0))) {
        return "";
    }
    Matrix encrypted = e.mult(nums);
    for (int i = 0; i < encrypted.size(1) * encrypted.size(2); i++) {
        encrypted.set(i, encrypted.get(i) % 29);
    }
    return n2let(encrypted);
}

std::string Hill::decrypt(const std::string &C) const {
    if (D.equal(Matrix(std::vector<int>(), 0, 0)) || D.size(1) != D.size(2) ||
        inv_mod(D).equal(Matrix(std::vector<int>(), 0, 0))) {
        return "";
    }
    Matrix nums = l2num(C, D);
    if (nums.equal(Matrix(std::vector<int>(), 0, 0))) {
        return "";
    }
    Matrix decrypted = D.mult(nums);
    for (int i = 0; i < decrypted.size(1) * decrypted.size(2); i++) {
        decrypted.set(i, decrypted.get(i) % 29);
    }
    return n2let(decrypted);
}

std::string Hill::decrypt(const std::string &C, const Matrix &D) {
    if (D.equal(Matrix(std::vector<int>(), 0, 0)) || D.size(1) != D.size(2) ||
        inv_mod(D).equal(Matrix(std::vector<int>(), 0, 0))) {
        return "";
    }
    Matrix d = D;
    for (int i = 0; i < d.size(1) * d.size(2); i++) {
        d.set(i, mod(d.get(i), 29));
    }
    Matrix nums = l2num(C, D);
    if (nums.equal(Matrix(std::vector<int>(), 0, 0))) {
        return "";
    }
    Matrix decrypted = D.mult(nums);
    for (int i = 0; i < decrypted.size(1) * decrypted.size(2); i++) {
        decrypted.set(i, decrypted.get(i) % 29);
    }
    return n2let(decrypted);
}

bool Hill::kpa(const std::vector<std::string> &P, const std::vector<std::string> &C, unsigned int n) {
    if (P.size() != C.size()) { return false; }
    if (P.empty() || C.empty()) { return false; }
    std::string plaintext;
    std::string ciphertext;
    for (int i = 0; i < P.size(); i++) {
        plaintext += P.at(i);
        ciphertext += C.at(i);
    }
    if (plaintext.empty() || ciphertext.empty()) { return false; }
    if (plaintext.length() != ciphertext.length()) { return false; }
    Matrix E(std::vector<int>(n * n, 1), n, n);
    Matrix plaintextNums = l2num(plaintext, E);
    Matrix ciphertextNums = l2num(ciphertext, E);
    plaintextNums = plaintextNums.trans();
    ciphertextNums = ciphertextNums.trans();
    if(row_reduce(ciphertextNums, plaintextNums)) {
        setD(plaintextNums.trans());
        setE(inv_mod(this->D));
        return true;
    }
    return false;
}

Matrix Hill::l2num(const std::string &s, const Matrix &E) const {
    std::string validCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ. ?";
    unsigned int n = E.size(1);
    unsigned int numColumns = (s.length() % n == 0) ? s.length() / n : s.length() / n + 1;
    unsigned int length = numColumns * n;
    std::vector<int> nums(length, 28); // fill with spaces for padding
    for (int i = 0; i < s.length(); i++) {
        char c = s.at(i);
        if (validCharacters.find(c) == std::string::npos) {
            return Matrix(std::vector<int>(), 0, 0);
        }
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
    return Matrix(nums, n, numColumns);
}

std::string Hill::n2let(const Matrix &A) const {
    std::string result;
    for (int i = 0; i < A.size(1) * A.size(2); i++) {
        char c = A.get(i);
        if (c == 28) {
            result += ' ';
        } else if (c == 27) {
            result += '?';
        } else if (c == 26) {
            result += '.';
        } else {
            result += (char) (A.get(i) + ASCII_OFFSET);
        }
    }
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
    if (!row_reduce(mat, result)) {
        return Matrix(std::vector<int>(), 0, 0);
    }
    return result;
//    for (int i = 0; i < A.size(1); i++) {
//        int n = mat.get(i, i);
//        if (n == 0) { break; }
//        int inverse = ZI29[n - 1];
//        row_mult(result, i, 0, result.size(2), inverse);
//        row_mult(mat, i, 0, mat.size(2), inverse);
//        for (int j = 0; j < A.size(1); j++) {
//            if (j != i) {
//                row_diff(result, j, 0, result.size(2), result, i, mat.get(j, i));
//                row_diff(mat, j, 0, mat.size(2), mat, i, mat.get(j, i));
//            }
//        }
//    }
//    if (!mat.equal(I)) {
//        return Matrix(std::vector<int>(), 0, 0);
//    }
//    return result;
}

unsigned int Hill::mod(int a, int b) const {
    int c = a % b;
    return (c < 0) ? c + b : c;
}

bool Hill::row_reduce(Matrix &A, Matrix &B) const {
    Matrix I(std::vector<int>(A.size(1) * A.size(2)), A.size(1), A.size(2));
    for (int i = 0; i < I.size(1); i++) {
        I.set(i, i, 1);
    }
    for (int i = 0; i < A.size(1); i++) {
        int n = A.get(i, i);
        if (n == 0) { break; }
        int inverse = ZI29[n - 1];
        row_mult(B, i, 0, B.size(2), inverse);
        row_mult(A, i, 0, A.size(2), inverse);
        for (int j = 0; j < A.size(1); j++) {
            if (j != i) {
                row_diff(B, j, 0, B.size(2), B, i, A.get(j, i));
                row_diff(A, j, 0, A.size(2), A, i, A.get(j, i));
            }
        }
    }
    if (!A.equal(I)) {
        return false;
    }
    return true;
};

void Hill::row_mult(Matrix &A, unsigned int i, unsigned int j, unsigned int k, unsigned int c) const {
    //For row i of Matrix A, multiply columns j through k by c, mod 29
    for (unsigned int col = j; col < k; col++) {
        A.set(i, col, mod(A.get(i, col) * c, 29));
    }
}

void
Hill::row_diff(Matrix &A, unsigned int i, unsigned int j, unsigned int k, Matrix &B, unsigned int l,
               unsigned int c) const {
    //Multiply columns j through k of row l of Matrix B by c and subtract from columns j through k of row i of Matrix A, mod 29
    Matrix m = B;
    for (unsigned int col = j; col < k; col++) {
        m.set(l, col, m.get(l, col) * c);
    }
    for (unsigned int col = j; col < k; col++) {
        A.set(i, col, mod(A.get(i, col) - m.get(l, col), 29));
    }
}

