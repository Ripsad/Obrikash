#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

void eratosthenes(std::vector<int>& numbers, int n)
{
    for(int i{2}; i <= n; ++i)
    {
        numbers[i - 2] = i;
    }

    int currentIndex{0};
    int currentNum{0};

    while(currentIndex < n)
    {
        if(numbers[currentIndex] != 0)
        {
            currentNum = numbers[currentIndex];
            for(int i{currentIndex + 1}; i < n; ++i)
            {
                if(numbers[i] % currentNum == 0)
                {
                    numbers[i] = 0;
                }
            }
        }
        currentIndex++;
    }
    numbers.erase(std::remove(numbers.begin(), numbers.end(), 0), numbers.end());
}

std::vector<int> fermat(const std::vector<int>& numbers, int n)
{
    std::vector<int> deliteli;
    int a,b;
    int m{std::ceil(std::sqrt(n))};
    int qSquared = m * m - n;
    while(true) {
        int q = std::sqrt(qSquared);
        if(q * q == qSquared) {
            a = m + q;
            b = m - q;
        }
        ++m;
        qSquared = m * m - n;
        if(m * m >= n)  break;
    }
    if(!(std::binary_search(numbers.begin(), numbers.end(), a)))
    {
        std::vector<int> deli(2);
        deli = fermat(numbers, a);
        deliteli.push_back(deli[0]);
        deliteli.push_back(deli[1]);
        deliteli.push_back(b);
    }
    else if(!(std::binary_search(numbers.begin(), numbers.end(), b)))
    {
        std::vector<int> deli = fermat(numbers, b);
        deliteli.push_back(deli[0]);
        deliteli.push_back(deli[1]);
        deliteli.push_back(a);
    }
    else {
        deliteli.push_back(a);
        deliteli.push_back(b);
    }
    
    return deliteli;
}

int main()
{
    int n;
    std::cin >> n;
    if(n % 2 == 0)
    {
        std::cout << "Число чётное. Метод Ферма не подходит.\n";
        return 0;
    }

    std::vector<int> numbers(n);
    eratosthenes(numbers, n);
   
    if(std::binary_search(numbers.begin(), numbers.end(), n))
    {
        std::cout << "Число - простое.\n";
        return 0;
    }
    
    std::vector<int> deliteli = fermat(numbers, n);
    std::cout << n << ": ";
    for(const auto& delitel : deliteli)
    {
        std::cout << delitel << ' ';
    }
    std::cout << '\n';

    return 0;
}