#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::locale loc("ru_RU.UTF-8");
    std::wcout.imbue(loc);

    std::wstring inputText;
    std::getline(std::wcin, inputText);

    for (wchar_t& c : inputText) {
        c = std::towlower(c); 
    }

    std::wcout << inputText << '\n';

    return 0;
}
