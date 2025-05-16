#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H
#include <string>
class CaesarCipher {
public:
    CaesarCipher(int shift);

private:
    static int shift_;
    static char input_;
};

#endif //CAESARCIPHER_H
