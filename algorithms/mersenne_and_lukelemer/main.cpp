#include <iostream>
#include <cmath>

// Функция для вычисления числа Мерсенна M_p
long long calculateMersenne(int p) {
    return (1LL << p) - 1; // 2^p - 1
}

// Функция для выполнения теста Люка-Лемера
bool lucasLehmerTest(int p) {
    if (p <= 2) {
        return false; // Мерсеннское число M_2 и M_3 не являются простыми
    }

    long long mersenne = calculateMersenne(p);
    long long s = 4;

    for (int i = 3; i <= p; ++i) {
        s = (s * s - 2) % mersenne;
    }

    return s == 0;
}

int main() {
    int p;
    
    std::cout << "Введите номер числа Мерсенна (p): ";
    std::cin >> p;

    if (lucasLehmerTest(p)) {
        std::cout << "Число Мерсенна M_" << p << " простое." << std::endl;
    } else {
        std::cout << "Число Мерсенна M_" << p << " не является простым." << std::endl;
    }

    return 0;
}
