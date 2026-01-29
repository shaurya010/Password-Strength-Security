#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

int main() {
    std::cout << "Welcome to the password entropy/strength calculator\n";

    std::string password;
    std::cout << "What is your password\n";
    std::getline(std::cin, password);

    int length = password.length();

    // Character set flags
    std::unordered_map<std::string, int> charset = {
        {"lower", 0},
        {"upper", 0},
        {"numbers", 0},
        {"punctuation", 0}
    };

    for (char c : password) {
        if (c >= 'a' && c <= 'z') {
            charset["lower"] = 26;
        } 
        else if (c >= 'A' && c <= 'Z') {
            charset["upper"] = 26;
        } 
        else if (c >= '0' && c <= '9') {
            charset["numbers"] = 10;
        } 
        else {
            charset["punctuation"] = 32;
        }
    }

    int character_set_size = 0;
    for (const auto &pair : charset) {
        character_set_size += pair.second;
    }

    std::cout << character_set_size << "\n";

    // Entropy calculation: length * log2(character_set_size)
    double password_entropy = length * (std::log(character_set_size) / std::log(2));

    std::cout << "Your password has an entropy of "
              << password_entropy << " bits\n";

    // Time to crack calculation
    double t = std::pow(character_set_size, length) /
               (2.0 * 1e9) / (86400 * 365.25);

    std::cout << "It would take " << t
              << " years to crack your password with a billion guesses per second "
              << "if there aren't any common words in your password\n";

    return 0;
}
