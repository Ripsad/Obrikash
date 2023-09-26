#include <iostream>
#include <vector>
#include <cmath>

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

// Функция для нахождения простых множителей числа методом Ферма
void fermatFactorization(int n) {
    std::vector<bool> isPrime;
    sieveOfEratosthenes(isPrime, n);
    
    std::cout << "Простые множители числа " << n << " и их кратности:" << std::endl;
    
    // Перебираем числа начиная с 2 до корня из n
    for (int a = 2; a * a <= n; ++a) {
        // Если a - простое число и a делит n, то продолжаем делить n на a и выводим a
        if (isPrime[a] && n % a == 0) {
            int count = 0;
            while (n % a == 0) {
                n /= a;
                ++count;
            }
            std::cout << a << " в степени " << count << std::endl;
        }
    }
    
    // Если n осталось больше 1, то это означает, что n - простое число
    if (n > 1) {
        std::cout << n << " в степени 1" << std::endl;
    }
}

int main() {
    int num;
    
    std::cout << "Введите нечетное число для факторизации: ";
    std::cin >> num;
    
    if (num <= 1 || num % 2 == 0) {
        std::cout << "Число должно быть нечетным и больше 1." << std::endl;
    } else {
        fermatFactorization(num);
    }
    
    return 0;
}
