#include <iostream>

int findSmallestNumber(int a) {
    if (a == 0) {
        return 0;
    }

    if (a == 1) {
        return 1;
    }

    if (a % 2 != 0) {
        return -1;  // Если a нечетное, то такое число b не существует.
    }

    int b = 0;
    int divisor = 9;

    while (divisor > 1) {
        while (a % divisor == 0) {
            a /= divisor;
            b = b * 10 + divisor;
        }
        divisor--;
    }
    int reversed = 0;
    while (b > 0) {
        int lastDigit = b % 10;
        reversed = reversed * 10 + lastDigit;
        b /= 10;
    }

    return (a == 1) ? reversed : -1;
}

int main() {
    int a;
    std::cin >> a;

    int result = findSmallestNumber(a);
    if (result == -1) {
        std::cout << "0\n";
    } else {
        std::cout << result << '\n';
    }

    return 0;
}
