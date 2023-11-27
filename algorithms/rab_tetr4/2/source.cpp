#include <iostream>
#include <map>

void count_chars(std::string s) {
    std::map<char, int> hash_table;

    for (const char& ch : s) {
        if (hash_table.find(ch) == hash_table.end()) {
            hash_table[ch] = 1;
        }
        else {
            hash_table[ch]++;
        }
    }

    for (auto& kv : hash_table) {
        std::cout << kv.first << " - " << kv.second << " raz" << '\n';
    }
}

int main() {
    count_chars("Hello, World!");
    return 0;
}