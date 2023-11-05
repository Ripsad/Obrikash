#include <iostream>

std::string binaryAddition(std::string num1, std::string num2) {
    std::string result = "";
    int carry = 0;

    while (num1.length() < num2.length()) {
        num1 = "0" + num1;
    }
    while (num2.length() < num1.length()) {
        num2 = "0" + num2;
    }

    for (int i = num1.length() - 1; i >= 0; i--) {
        int bit1 = num1[i] - '0';
        int bit2 = num2[i] - '0';

        int sum = bit1 ^ bit2 ^ carry;
        carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);

        result = std::to_string(sum) + result;
    }

    if (carry) {
        result = "1" + result;
    }

    return result;
}

int main() {
    std::string binaryNum1, binaryNum2;
    
    std::cout << "First number: ";
    std::cin >> binaryNum1;
    std::cout << "Second number: ";
    std::cin >> binaryNum2;

    std::string sum = binaryAddition(binaryNum1, binaryNum2);

    std::cout << "Sum: " << sum << '\n';

    return 0;
}
