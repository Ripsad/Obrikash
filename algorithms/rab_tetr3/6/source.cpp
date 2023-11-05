#include <iostream>

int main() {
    int dividend, divisor;
    std::cout << "Dividend: ";
    std::cin >> dividend;
    std::cout << "Divisor: ";
    std::cin >> divisor;

    if (divisor == 0) {
        std::cout << "Error - divide by 0\n";
    } else {
        int quotient = 0;
        int remainder = 0;

        if (dividend < 0) {
            dividend = -dividend;
            divisor = -divisor;
        }

        for (int i = 31; i >= 0; i--) {
            remainder <<= 1;
            remainder |= (dividend >> i) & 1;
            if (remainder >= divisor) {
                remainder -= divisor;
                quotient |= 1 << i;
            }
        }

        std::cout << "Answer: " << quotient << '\n';
        std::cout << "Reaminder: " << remainder << '\n';
    }

    return 0;
}
