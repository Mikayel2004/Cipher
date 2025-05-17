#ifndef XORCIPHER_H
#define XORCIPHER_H
#include <string>

class XORCipher {
public:
    explicit XORCipher (const std::string& key);
    std::string encrypt(const std::string &text) const;
    std::string decrypt(const std::string &text) const;
private:
    std::string key_;
    std::string repeat_keyword(size_t length) const;
};

#endif //XORCIPHER_H
