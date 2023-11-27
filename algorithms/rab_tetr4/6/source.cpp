#include <iostream>
#include <unordered_map>
#include <string>

char first_non_repeating_character(std::string s) {
    std::unordered_map<char, int> hash_table;

    for (char& c : s) {
        hash_table[c]++;
    }

    for (char& c : s) {
        if (hash_table[c] == 1) {
            return c;
        }
    }

    return '\0';
}

int main() {

    std::string s = "minimum";
    char result = first_non_repeating_character(s);
    if (result != '\0') {
        std::cout << "result: " << result << '\n';
    } else {
        std::cout << "all symbols are unique\n";
    }

    return 0;
}