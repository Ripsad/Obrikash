#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{
    int n;
    std::cin >> n;
    double x,y,z;

    for(int i{0}; i < n; ++i)
    {
        std::string name, surname;
        std::cin >> name >> surname;
        double temp1,temp2,temp3;
        std::cin >> temp1 >> temp2 >> temp3;
        x += temp1;
        y += temp2;
        z += temp3;
    }
    std::cout << std::fixed << std::setprecision(1) << 
    (round(x/n * 10)/10) << ' ' 
    << (round(y/n * 10)/10) << ' ' << (round(z/n * 10)/10);

    return 0;
}