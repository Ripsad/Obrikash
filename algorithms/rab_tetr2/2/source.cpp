#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

void factorizate(const std::vector<int>& numbers, int n) 
{
    for (int prime : numbers) {
        int count = 0;
        while (n % prime == 0) {
            ++count;
            n /= prime;
        }
        if (count > 0) {
            std::cout << prime << " в степени " << count << '\n';
        }
    }

    if (n > 1) {
        std::cout << n << " в степени 1" << '\n';
    }
}

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
            for(int i{currentIndex + 1}; i < n; ++i) {
                if(numbers[i] % currentNum == 0) numbers[i] = 0;
            }
        }
        ++currentIndex;
    }
    numbers.erase(std::remove(numbers.begin(), numbers.end(), 0), numbers.end());
}
int main()
{
    unsigned int n;
    std::cin >> n;
    
    std::vector<int> numbers(n);
    eratosthenes(numbers, n);

   
    if(std::binary_search(numbers.begin(), numbers.end(), n))
    {
        std::cout << "Число - простое.\n";
        return 0;
    }

    factorizate(numbers, n);

    return 0;
}