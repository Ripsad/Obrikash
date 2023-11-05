#include <iostream>

int biba_i_boba(int a,int b,int c)
{
    if (c <= 1)
        return a;
    if (c == 2)
        return b;
    
    return biba_i_boba(a,b,c - 1) * biba_i_boba(a,b,c - 2);

}

int main()
{
    int a,b,c;
    std::cin >> a >> b >> c;

    std::cout << biba_i_boba(a,b,c);
    return 0;
}