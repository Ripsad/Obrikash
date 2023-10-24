#include <iostream>
#include <algorithm>

int* big_num(int count)
{
	int* num = new int[count];
	for (int i{ 0 }; i < count - 1; ++i)
		num[i] = rand() % 10;

	int hnum{ 0 };
	while (true) {
		hnum = rand() % 10;
		if (hnum != 0) break;
	}
	num[count - 1] = hnum;
	return num;
}

int* addNumbers(const int* num1, const int* num2, int count)
{
	int maxLength{ count + 1 };
	int* result = new int[maxLength + 1];
	int carry{ 0 };


	for (int i{ 0 }; i < maxLength; ++i)
	{
		int digit1 = (i < count) ? num1[i] : 0;
		int digit2 = (i < count) ? num2[i] : 0;
		
		int total = digit1 + digit2 + carry;
		carry = total / 10;
		result[i] = total % 10;
	}
	if (carry > 0) result[maxLength] = carry;

	return result;
}

int* subractNumbers(const int* num1, const int* num2, int count)
{
	int* result = new int[count];
	int borrow{ 0 };


	for (int i{ 0 }; i < count; ++i)
	{
		int digit1 = (i < count) ? num1[i] : 0;
		int digit2 = (i < count) ? num2[i] : 0;

		int diff = digit1 - digit2 - borrow;
		
		if (diff < 0) {
			diff += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		result[i] = diff;
	}

	return result;
}

bool greater(const int* num1, const int* num2, int count)
{
	for (int i{ count - 1 }; i >= 0; i--)
	{
		if (num1[i] > num2[i]) return true;
		else if (num1[i] < num2[i]) return false;
		else return true;
	}
	return true;
}

void printNumber(const int* number, int count, char sign = '+')
{
	if (sign == '-') std::cout << '-';
	

	if (number[count - 1] != 0)
		std::cout << number[count - 1];

	for (int i{ count - 2}; i >= 0; --i) {
		std::cout << number[i];
	}
}

int main()
{
	srand(time(NULL));
	srand(rand());

	int count{ 0 };
	while (true) {
		std::cout << "Enter a number: ";
		std::cin >> count;
		if (count > 0) break;
	}

	int* num1 = big_num(count);
	printNumber(num1, count);
	std::cout << '\n';

	int* num2 = big_num(count);
	printNumber(num2, count);
	std::cout << "\n+ = ";

	int* addition = addNumbers(num1, num2, count);
	printNumber(addition, count+1);
	std::cout << "\n- = ";

	int* subtraction;
	if (greater(num1, num2, count)) {
		subtraction = subractNumbers(num1, num2, count);
		printNumber(subtraction, count);
	}
	else {
		subtraction = subractNumbers(num2, num1, count);
		printNumber(subtraction, count, '-');
	}
	

	delete[] num1;
	delete[] num2;
	delete[] addition;
	delete[] subtraction;

	return 0;
}