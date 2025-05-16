#include "ciphers/VigenereCipher.h"
#include <cctype>
#include <stdexcept>

VigenereCipher::VigenereCipher(const std::string &keyword) : keyword_(keyword) {
    if (keyword.empty()) {
        throw std::runtime_error("Keyword cannot be empty");
    }
    for (const char c : keyword) {
        if (!isalpha(c)) {
            throw std::runtime_error("Keyword must contain only letters");
        }
    }
}

std::string VigenereCipher::repeat_keyword(size_t length) const {
    std::string result;
    for (size_t i = 0; i < length; ++i) {
        result += keyword_[i % keyword_.length()];
    }
    return result;
}

std::string VigenereCipher::encrypt(const std::string &text) const {
    std::string result;
    std::string key = repeat_keyword(text.length());
    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int textNum = text[i] - base; // A=0, ..., Z=25
            int keyNum = toupper(key[i]) - 'A'; // Keyword letter to 0-25
            int cipherNum = (textNum + keyNum) % 26; // Fixed: Add instead of subtract
            result += static_cast<char>(cipherNum + base);
        } else {
            result += text[i];
        }
    }
    return result;
}

std::string VigenereCipher::decrypt(const std::string &text) const {
    std::string result;
    std::string key = repeat_keyword(text.length());
    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int textNum = text[i] - base;
            int keyNum = toupper(key[i]) - 'A';
            int plainNum = (textNum - keyNum + 26) % 26; // Already correct
            result += static_cast<char>(plainNum + base);
        } else {
            result += text[i];
        }
    }
    return result;
}