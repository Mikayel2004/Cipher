#include <iostream>
#include "ciphers/CaesarCipher.h"
#include "ciphers/VigenereCipher.h"

int main() {
    // Test Caesar Cipher
    CaesarCipher caesar(3);
    std::string text = "HELLO";
    std::string caesarEncrypted = caesar.encrypt(text);
    std::string caesarDecrypted = caesar.decrypt(caesarEncrypted);
    std::cout << "Caesar Cipher:" << std::endl;
    std::cout << "Encrypted: " << caesarEncrypted << std::endl;
    std::cout << "Decrypted: " << caesarDecrypted << std::endl;

    // Test Vigenère Cipher
    VigenereCipher vigenere("KEY");
    std::string vigenereEncrypted = vigenere.encrypt(text);
    std::string vigenereDecrypted = vigenere.decrypt(vigenereEncrypted);
    std::cout << "\nVigenère Cipher:" << std::endl;
    std::cout << "Encrypted: " << vigenereEncrypted << std::endl;
    std::cout << "Decrypted: " << vigenereDecrypted << std::endl;

    return 0;
}