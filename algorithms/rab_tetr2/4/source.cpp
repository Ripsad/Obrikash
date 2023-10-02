#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
int main()
{
    int mersenne{};
    std::cin >> mersenne;

    std::vector<long long> mersenneNumbers(20);
    for(int n{0}; n < 20; ++n) {
        mersenneNumbers[n] = std::pow(2, n+1) - 1;
    }
    int index;
    std::vector<long long>::iterator it{std::find(mersenneNumbers.begin(), mersenneNumbers.end(), mersenne)};
    if(it != mersenneNumbers.end())
        index = std::distance(mersenneNumbers.begin(), it);
    else {
        std::cout << "Не число Мерсенна.\n"; return 0;
    }

    int s{4};
    int k{1};
    while(k != index) {
        s = ((s * s) - 2 ) % mersenne;
        ++k;
    }
    if(s == 0)
        std::cout << "Число Мерсенна " << mersenne << " - простое.\n";
    else
        std::cout << "Число Мерсенна " << mersenne << " - составное.\n";

 

    return 0;
}