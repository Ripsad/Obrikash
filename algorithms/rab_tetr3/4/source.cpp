#include <iostream>
#include <string>
#include <vector>


std::string multiplyNumbers(const std::string& num1, const std::string& num2)
{
    int len1 = static_cast<int>(num1.length());
    int len2 = static_cast<int>(num2.length());
    std::vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    int start = 0;
    while (start < result.size() - 1 && result[start] == 0) start++;

    std::string finalResult{ "" };
    for (int i = start; i < result.size(); i++) {
        finalResult += result[i] + '0';
    }

    return finalResult;
}

int main()
{

    std::string num1;
    std::string num2;
    std::cout << "1 Number: ";
    std::cin >> num1;

    std::cout << "2 Number: ";
    std::cin >> num2;

    std::cout << num1 << " * " << num2 << " = ";
    std::string result = multiplyNumbers(num1, num2);

    std::cout << result << '\n';


    return 0;
}