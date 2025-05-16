#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H
#include <string>

class VigenereCipher {
public:
    explicit VigenereCipher (const std::string& keyword);
    std::string encrypt(const std::string &text) const;
    std::string decrypt(const std::string &text) const;
private:
    std::string keyword_;
    std::string repeat_keyword(size_t length) const;
};

#endif //VIGENERECIPHER_H
