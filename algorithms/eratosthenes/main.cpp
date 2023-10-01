#include <iostream>
#include <vector>
#include <cmath>


void eratosthenes(int n, std::vector<bool>& primes)
{
    primes.resize(n, true);

    primes[0] = primes[1] = false;

    for(int p{2}; p * p <= n; ++p)
    {
        if(primes[p])
        {
            for(int i = p * p; i <= n; i += p)
            {
                primes[i] = false;
            }
        }
    }

 
}

bool fermatFactorization(long long n, long long& a, long long& b)
{
    if(n % 2 == 0) return false;

    long long m = static_cast<long long>(std::sqrt(n));
    long long yS = m * m - n;

    while(true)
    {
        long long y = static_cast<long long>(std::sqrt(yS));
        if(y * y == yS)
        {
            a = m + y;
            b = m - y;
            return true;
        }
        ++m;
        yS = m * m - n;
        if(m * m >= n)
        {
            break;
        }
    }
    return false;

}

int main()
{
    std::cout << "Введите нечетное число: ";
    int n{};
    std::cin >> n;
    if(n % 2 == 0) {
        std::cout << "not valid value.\n";
        return -1;
    }


    std::vector<bool> primes; // решето Эратосфена
    eratosthenes(n, primes);
    
    long long a,b;
    std::cout << fermatFactorization(n,a,b) << '\n';

    std::cout << "Число " << n << " можно разложить на " << a << " и "
              << b << ".\n";

    return 0;
}