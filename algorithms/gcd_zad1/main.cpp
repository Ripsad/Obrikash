#include <iostream>

int gcd(int x, int y)
{
    while(y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }

    return x;
}

int gcd_3(int x, int y, int z)
{
    int temp = gcd(x, y);

    temp = gcd(temp, z);
    return temp;
}

int main()
{
    int num1, num2, num3;
    std::cout << "3 Numbers: ";
    std::cin >> num1 >> num2 >> num3;

    int x{gcd_3(num1,num2,num3)};

    std::cout << "Answer is: " << x << '\n';

    return 0;
}