#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include "ciphers/CaesarCipher.h"
#include "ciphers/VigenereCipher.h"
#include "ciphers/XORCipher.h"
#include "ciphers/XORCipher.h"

// Function to clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to validate and get a positive integer for Caesar shift
int getValidShift() {
    int shift;
    while (true) {
        std::cout << "Enter shift value (positive integer): ";
        if (std::cin >> shift && shift >= 0) {
            clearInputBuffer();
            return shift;
        } else {
            std::cout << "Invalid input. Please enter a positive integer.\n";
            clearInputBuffer();
        }
    }
}

// Function to validate and get a non-empty alphabetic keyword
std::string getValidKeyword() {
    std::string keyword;
    while (true) {
        std::cout << "Enter keyword (letters only): ";
        std::getline(std::cin, keyword);
        bool valid = !keyword.empty();
        for (char c : keyword) {
            if (!isalpha(c)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            return keyword;
        }
        std::cout << "Invalid keyword. Use letters only, non-empty.\n";
    }
}

// Function to get plaintext (any string)
std::string getPlaintext() {
    std::string text;
    std::cout << "Enter text to encrypt: ";
    std::getline(std::cin, text);
    return text;
}

int main() {
    while (true) {
        std::cout << "\nCipher Program\n";
        std::cout << "1. Caesar Cipher\n";
        std::cout << "2. Vigenère Cipher\n";
        std::cout << "3. XOR Cipher\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose a cipher (1-4): ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        if (choice == 4) {
            std::cout << "Exiting program.\n";
            break;
        }

        if (choice < 1 || choice > 3) {
            std::cout << "Invalid choice. Please select 1, 2, 3, or 4.\n";
            continue;
        }

        // Get plaintext for all ciphers
        std::string text = getPlaintext();
        if (text.empty()) {
            std::cout << "Text cannot be empty. Try again.\n";
            continue;
        }

        try {
            if (choice == 1) {
                // Caesar Cipher
                int shift = getValidShift();
                CaesarCipher caesar(shift);
                std::string encrypted = caesar.encrypt(text);
                std::string decrypted = caesar.decrypt(encrypted);
                std::cout << "Caesar Cipher (shift=" << shift << "):\n";
                std::cout << "Encrypted: " << encrypted << "\n";
                std::cout << "Decrypted: " << decrypted << "\n";
            } else if (choice == 2) {
                // Vigenère Cipher
                std::string keyword = getValidKeyword();
                VigenereCipher vigenere(keyword);
                std::string encrypted = vigenere.encrypt(text);
                std::string decrypted = vigenere.decrypt(encrypted);
                std::cout << "Vigenère Cipher (keyword=" << keyword << "):\n";
                std::cout << "Encrypted: " << encrypted << "\n";
                std::cout << "Decrypted: " << decrypted << "\n";
            } else if (choice == 3) {
                // XOR Cipher
                std::string keyword = getValidKeyword();
                XORCipher xorCipher(keyword);
                std::string encrypted = xorCipher.encrypt(text);
                std::string decrypted = xorCipher.decrypt(encrypted);
                std::cout << "XOR Cipher (keyword=" << keyword << "):\n";
                std::cout << "Encrypted: " << encrypted << "\n";
                std::cout << "Decrypted: " << decrypted << "\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
            continue;
        }
    }

    return 0;
}