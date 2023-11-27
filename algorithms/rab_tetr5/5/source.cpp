#include <iostream>

int F(int n) {
    if (n == 1)
        return 1;
    else if (n % 2 == 0)
        return F(n / 2);
    else
        return F(n / 2) + F(n / 2 + 1);
}

int main() {
    int n{};
    std::cout << "Enter n: ";
    std::cin >> n;
    
    std::cout << "F(" << n << ") = " << F(n) << '\n';
    return 0;
}
