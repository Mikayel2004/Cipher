# Cipher Project

A C++ application for encrypting and decrypting text using classic cryptographic ciphers. This project implements the Caesar, Vigenère, and XOR ciphers, allowing users to interactively select a cipher, input parameters, and process text.

## Features

- **Caesar Cipher**: Encrypts text by shifting each letter by a fixed number of positions in the alphabet (e.g., shift=3 turns "HELLO" into "KHOOR").
- **Vigenère Cipher**: Uses a keyword to apply varying shifts to each letter (e.g., keyword="KEY" turns "HELLO" into "RIJVS").
- **XOR Cipher**: Applies a bitwise XOR operation with a keyword (e.g., keyword="KEY" turns "HELLO" into "NATBK").
- Interactive command-line interface to choose a cipher, input shift/keyword, and text.
- Preserves letter case and skips non-alphabetic characters (e.g., spaces, punctuation).
- Robust input validation to handle invalid shifts or keywords.
- Built with CMake for cross-platform compatibility.

## Prerequisites

- **C++ Compiler**: GCC, Clang, or any C++11-compatible compiler.
- **CMake**: Version 3.10 or higher.
- **Make**: For building the project.
- **Operating System**: Tested on Linux (e.g., Ubuntu); should work on macOS and Windows with adjustments.

Install prerequisites on Ubuntu:
```bash
sudo apt-get update
sudo apt-get install build-essential cmake
```

## Project Structure

```
Cipher/
├── main.cpp              # Interactive program to select and use ciphers
├── ciphers/
│   ├── CaesarCipher.h    # Caesar cipher header
│   ├── CaesarCipher.cpp  # Caesar cipher implementation
│   ├── VigenereCipher.h  # Vigenère cipher header
│   ├── VigenereCipher.cpp# Vigenère cipher implementation
│   ├── XorCipher.h       # XOR cipher header
│   ├── XorCipher.cpp     # XOR cipher implementation
├── CMakeLists.txt        # CMake configuration file
```

## Building the Project

1. Clone the repository (or copy your local project):
   ```bash
   git clone https://github.com/Mikayel2004/KalmanFilter.git
   cd KalmanFilter
   ```
   Note: The repository name may change to reflect the cipher project.

2. Create a build directory and run CMake:
   ```bash
   rm -rf build
   mkdir build
   cd build
   cmake ..
   ```

3. Compile the project:
   ```bash
   make
   ```

4. Run the executable:
   ```bash
   ./cipher
   ```

## Usage

The program provides an interactive command-line interface:

1. **Select a Cipher**:
   - Enter `1` for Caesar Cipher.
   - Enter `2` for Vigenère Cipher.
   - Enter `3` for XOR Cipher.
   - Enter `4` to exit.

2. **Input Parameters**:
   - For Caesar: Enter a positive integer shift (e.g., `3`).
   - For Vigenère/XOR: Enter a keyword containing only letters (e.g., `KEY`).
   - Enter the text to encrypt (e.g., `HELLO`).

3. **Output**:
   - The program displays the encrypted and decrypted text.
   - Example:
     ```
     Welcome to the Cipher Program

     Available Ciphers:
     1. Caesar Cipher
     2. Vigenère Cipher
     3. XOR Cipher
     4. Exit
     Choose a cipher (1-4): 2
     Enter text to encrypt: HELLO
     Enter keyword (letters only): KEY
     Vigenère Cipher (keyword=KEY):
     Encrypted: RIJVS
     Decrypted: HELLO
     ```

## Example Outputs

- **Caesar Cipher** (shift=3, text="HELLO"):
  - Encrypted: `KHOOR`
  - Decrypted: `HELLO`
- **Vigenère Cipher** (keyword="KEY", text="HELLO"):
  - Encrypted: `RIJVS`
  - Decrypted: `HELLO`
- **XOR Cipher** (keyword="KEY", text="HELLO"):
  - Encrypted: `NATBK`
  - Decrypted: `HELLO`

## Notes

- **Letter Mapping**: All ciphers use the mapping A=0, B=1, ..., Z=25 for alphabetic characters.
- **Case Preservation**: The ciphers preserve the case of input letters (e.g., "HeLlO" maintains mixed case).
- **Non-Alphabetic Characters**: Spaces, punctuation, and other characters are unchanged.
- **Error Handling**: The program validates inputs (e.g., non-numeric shifts, non-alphabetic keywords) and provides clear error messages.
- **Security**: These ciphers are for educational purposes and not suitable for modern cryptographic security.

## Future Plans

- Add more ciphers (e.g., Substitution Cipher, Playfair Cipher).
- Support file input/output for processing large texts.
- Add an option to decrypt ciphertext directly.
- Improve the interface with a graphical or web-based frontend.

## Contributing

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add new feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

Please ensure code follows the project’s style (e.g., consistent naming, error handling).

## License

This project is licensed under the MIT License. See the `LICENSE` file for details (to be added).

## Contact

For questions or suggestions, contact [Mikayel2004](https://github.com/Mikayel2004) or open an issue on the repository.