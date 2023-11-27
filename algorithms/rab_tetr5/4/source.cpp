#include <iostream>
#include <cmath>

int sum_of_digits(int n) {
    if (n == 0)
        return 0;
    else
        return (n % 10 + sum_of_digits(n / 10));
}

int main() {
    int number{};
    std::cin >> number;
    std::cout << "Sum " << number << " = " << sum_of_digits(abs(number)) << '\n';
    return 0;
}
