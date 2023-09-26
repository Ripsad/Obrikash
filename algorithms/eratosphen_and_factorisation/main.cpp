#include <iostream>
#include <vector>

// Функция для построения решета Эратосфена
void sieveOfEratosthenes(std::vector<bool>& isPrime, int n) {
    isPrime.resize(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

// Функция для факторизации числа и вывода результатов
void factorize(int n) {
    std::vector<bool> isPrime;
    sieveOfEratosthenes(isPrime, n);
    
    std::cout << "Простые множители числа " << n << " и их кратности:" << std::endl;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                ++count;
            }
            if (count > 0) {
                std::cout << i << " в степени " << count << std::endl;
            }
        }
    }
    
    if (n > 1) {
        std::cout << n << " в степени 1" << std::endl;
    }
}

int main() {
    int num;
    
    std::cout << "Введите число для факторизации: ";
    std::cin >> num;
    
    if (num <= 1) {
        std::cout << "Число должно быть больше 1." << std::endl;
    } else {
        factorize(num);
    }
    
    return 0;
}
