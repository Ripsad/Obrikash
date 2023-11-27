#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    if (a == b)
        return a;
    else if (a > b)
        return gcd(a-b,b);
    else
        return gcd(a, b-a);
}

int main() {
    int a,b;
    std::cout << "Enter 2 numbers(through space): ";
    std::cin >> a >> b;
    std::cout << "(" << a << ", " << b << ") = " << gcd(abs(a), abs(b)) << '\n';
    return 0;
}
