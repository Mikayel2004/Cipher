#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <string>

class CaesarCipher {
public:
    explicit CaesarCipher(int shift);
    std::string encrypt(const std::string &text) const;
    std::string decrypt(const std::string &text) const;

private:
    int shift_;
};

#endif // CAESARCIPHER_H
