#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        return 1;
    }

    std::string inputText;
    std::string bannedChars = "user agreement";
    std::transform(bannedChars.begin(), bannedChars.end(), bannedChars.begin(), ::tolower); // Преобразуем в нижний регистр

    char c;
    while (inputFile.get(c)) {
        char lowerC = tolower(c);
        if (bannedChars.find(lowerC) == std::string::npos) {
            outputFile << c;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}