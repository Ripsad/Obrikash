#include <iostream>
#include <vector>

std::vector<int> sundaram(int n)
{
    int n_half = (n - 1) / 2;
    std::vector<bool> marked(n_half + 1, false);
    std::vector<int> primes;

    for(int i = 1; i <= n_half; ++i)
    {
        int j = i;
        while((i + j + 2 * i * j) <= n_half) {
            marked[i + j + 2 * i * j] = true;
            j++;
        }
    }
    if(n > 2) {
        primes.push_back(2);
    }

    for(int i = 1; i <= n_half; ++i)
    {
        if(!marked[i])
            primes.push_back(2 * i + 1);
    }

    return primes;
}

int main() {
    int n;
    std::cout << "Введите число N: ";
    std::cin >> n;

    std::vector<int> primes = sundaram(n);
    std::cout << "Простые числа найденные с помощью решето Сундарама:\n";
    for(int i{0}; i < primes.size(); ++i)
    {
        if(i % 10 == 0)
            std::cout << '\n';
        std::cout << primes[i] << '\t';
    }
    std::cout << '\n';
    return 0;
}
