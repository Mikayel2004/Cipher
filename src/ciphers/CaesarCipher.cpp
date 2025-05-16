#include "ciphers/CaesarCipher.h"

CaesarCipher::CaesarCipher(int shift) : shift_(shift) {}

std::string CaesarCipher::encrypt(const std::string &text) const {
    std::string result;
    for (const auto c : text) {
        if (isalpha(c)) {
            const char base = isupper(c) ? 'A' : 'a';
            result += static_cast<char>((c - base + shift_) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

std::string CaesarCipher::decrypt(const std::string &text) const {
    return CaesarCipher(-shift_).encrypt(text);
}