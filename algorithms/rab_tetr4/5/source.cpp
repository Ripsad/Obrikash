#include <iostream>
#include <unordered_set>
#include <vector>

std::string first_repeating_element(std::vector<std::string>& arr) {
    std::unordered_set<std::string> hash_table;

    for (const auto& element : arr) {
        if (hash_table.find(element) != hash_table.end()) {
            return element;
        }
        else {
            hash_table.insert(element);
        }
    }

    return "";
}

int main() {
    // Тестирование функции
    std::vector<std::string> arr = {"a", "b", "c", "d", "c", "e", "f"};
    std::string result = first_repeating_element(arr);
    if (!result.empty()) {
        std::cout << "Element: " << result << '\n';
    } else {
        std::cout << "no elements repeated\n";
    }
    return 0;
}
