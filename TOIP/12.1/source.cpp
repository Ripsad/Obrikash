#include <iostream>

void printReverse(int n)
{
	if (n <= 0)
		return;
	int num;
	std::cin >> num;

	printReverse(n - 1);
	std::cout << num << ' ';
}

int main()
{
	int n{};
	std::cin >> n;

	printReverse(n);


	return 0;
}