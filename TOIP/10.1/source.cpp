#include <iostream>

int main()
{
    double x{};
    std::cin >> x;
    double *ptr1{&x};
    double **ptr2{&ptr1};
    std::cout << **ptr2;

    return 0;
}