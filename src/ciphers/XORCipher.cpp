#include "ciphers/XORCipher.h"
#include <cctype>
#include <stdexcept>

XORCipher::XORCipher(const std::string& key) : key_(key) {
    if (key.empty()) {
        throw std::invalid_argument("Key cannot be empty");
    }
    for (const char c : key) {
        if (!isalpha(c)) {
            throw std::invalid_argument("Key must contain only letters");
        }
    }
}

std::string XORCipher::repeat_keyword(size_t length) const {
    std::string result;
    for (size_t i = 0; i < length; ++i) {
        result += key_[i % key_.length()];
    }
    return result;
}

std::string XORCipher::encrypt(const std::string& text) const {
    std::string result;
    std::string key = repeat_keyword(text.length());
    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int textNum = text[i] - base; // A=0, ..., Z=25
            int keyNum = toupper(key[i]) - 'A'; // Key letter to 0-25
            int cipherNum = (textNum ^ keyNum) % 26; // XOR and modulo 26
            result += static_cast<char>(cipherNum + base);
        } else {
            result += text[i];
        }
    }
    return result;
}

std::string XORCipher::decrypt(const std::string& text) const {
    // XOR is its own inverse, so decryption is the same as encryption
    return encrypt(text);
}