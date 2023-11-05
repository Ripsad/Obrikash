#include <iostream>

long long fastPow(long long base, long long exp)
{
	if (exp == 0)
		return 1;
	if (exp % 2 == 0) {
		long long halfPow{ fastPow(base, exp / 2) };
		return halfPow * halfPow;
	}
	else {
		long long halfPow{ fastPow(base,(exp - 1) / 2) };
		return base * halfPow * halfPow;
	}
}

int main()
{
	long long num, pow;
	std::cin >> num >> pow;
	std::cout << fastPow(num, pow);
	return 0;
}