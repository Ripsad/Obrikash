#include <iostream>

int gcd_subtraction(int first, int second)
{
    int dif{0};
    bool flag = false;
    while(flag == false)
    {
        if(first == second)
        {
            flag = true;
        }
        else if(first < second)
        {
            dif = second - first;
            second = first;
            first = dif;
        }
        else
        {
            dif = first - second;
            first = second;
            second = dif;
        }
    }
    return first;
}

int gcd_subtraction_4(int first, int second, int third, int forth)
{
    return gcd_subtraction(gcd_subtraction(first, second), gcd_subtraction(third, forth));
}

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
    std::cout << "3 числа: ";
    std::cin >> num1 >> num2 >> num3;

    int x{gcd_3(num1,num2,num3)};

    std::cout << "Ответ: " << x << '\n';

    std::cout << "4 числа: ";
    int numb1, numb2, numb3, numb4;
    std::cin >> numb1 >> numb2 >> numb3 >> numb4;
    int y{gcd_subtraction_4(numb1,numb2,numb3,numb4)};
    std::cout << "Ответ: " << y << '\n';

    return 0;
}