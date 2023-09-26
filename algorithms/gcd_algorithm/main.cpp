#include <iostream>
#include <cmath>

void lcd(int x)
{
    int divider{};
    int count{};

    for(int i{2}; i <= sqrt(x); ++i) {
        if ((x % i) == 0) {
            divider = i;
            while(x % i == 0) {
                count++;
                x /= i;
            }

        std::cout << "the least divider: " << divider << '\n';
        std::cout << "amount of divides: " << count << '\n';
        return;
        }
    }
    std::cout << "the number is prime.\n";
}

int gcd(int x, int y)
{
    if(x == y)
        return x;
    
    if(x > y)
        return gcd(x-y, y);
    else
        return gcd(x, y-x);

    return 0;
}

int main()
{
    lcd(13);

    return 0;
}