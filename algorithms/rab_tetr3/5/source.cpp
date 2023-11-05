#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

std::string subtract(const std::string& num1, const std::string& num2) {
    int len = std::max(num1.length(), num2.length());
    std::string result(len, '0');
    int borrow = 0;

    for (int i = 1; i <= len; i++) {
        int a = i <= num1.length() ? (num1[num1.length() - i] - '0') : 0;
        int b = i <= num2.length() ? (num2[num2.length() - i] - '0') : 0;
        int diff = a - b - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result[len - i] = (diff % 10) + '0';
    }

    while (result.length() > 1 && result[0] == '0') {
        result = result.substr(1);
    }

    return result;
}

std::string add(const std::string& num1, const std::string& num2) {
    int len = std::max(num1.length(), num2.length());
    std::string result(len, '0');
    int carry = 0;

    for (int i = 1; i <= len; i++) {
        int a = i <= num1.length() ? (num1[num1.length() - i] - '0') : 0;
        int b = i <= num2.length() ? (num2[num2.length() - i] - '0') : 0;
        int sum = a + b + carry;
        result[len - i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry > 0) {
        result = std::to_string(carry) + result;
    }

    return result;
}


std::string karatsubaMultiplication(const std::string& num1, const std::string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();

    if (len1 == 1 || len2 == 1) {
        return std::to_string(std::stoll(num1) * std::stoll(num2));
    }

    int maxLen = std::max(len1, len2);

    if (maxLen % 2 != 0) {
        maxLen++;
    }

    int mid = maxLen / 2;

    std::string a = num1.substr(0, len1 - mid);
    std::string b = num1.substr(len1 - mid);
    std::string c = num2.substr(0, len2 - mid);
    std::string d = num2.substr(len2 - mid);

    std::string ac = karatsubaMultiplication(a, c);
    std::string bd = karatsubaMultiplication(b, d);
    std::string abcd = karatsubaMultiplication(add(a, b), add(c, d));

    std::string adbc = subtract(subtract(abcd, ac), bd);

    for (int i = 0; i < maxLen; i++) {
        ac += "0";
    }

    for (int i = 0; i < mid; i++) {
        adbc += "0";
    }

    return add(add(ac, adbc), bd);
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
 
    std::string karatsuba = karatsubaMultiplication(num1, num2);
    std::cout << "Karatsuba!: " << karatsuba << '\n';

    return 0;
}