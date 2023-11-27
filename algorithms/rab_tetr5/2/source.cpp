#include <iostream>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    for(int n{1}; n <= 20; n++)
        std::cout << "n = " << n << " is " << fibonacci(n) << '\n';
    return 0;
}
