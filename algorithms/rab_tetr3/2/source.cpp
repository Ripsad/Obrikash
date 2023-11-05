#include <iostream>
#include <algorithm>

int* addNumbers(const int* num1, const int* num2, int len1, int len2)
{
	int max{ std::max(len1,len2) };
	int* result = new int[max + 1];
	int carry{ 0 };


	for (int i{ 0 }; i < max; ++i)
	{
		int digit1 = (i < len1) ? num1[i] : 0;
		int digit2 = (i < len2) ? num2[i] : 0;

		int total = digit1 + digit2 + carry;
		carry = total / 10;
		result[i] = total % 10;
	}
	if (carry > 0) result[max] = carry;
	else result[max] = 0;

	return result;
}

int* subractNumbers(const int* num1, const int* num2, int len1, int len2)
{
	int max = std::max(len1, len2);
	int* result = new int[max];
	int borrow{ 0 };


	for (int i{ 0 }; i < max; ++i)
	{
		int digit1 = (i < len1) ? num1[i] : 0;
		int digit2 = (i < len2) ? num2[i] : 0;

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

bool greater(const int* num1, const int* num2, int len1, int len2)
{
	if (len1 != len2)
		return(len1 > len2);
	for (int i{ len1 - 1 }; i >= 0; i--)
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

	for (int i{ count - 2 }; i >= 0; --i) {
		std::cout << number[i];
	}
}

int main()
{
	std::cout << "1 Number: ";
	std::string temp1;
	std::cin >> temp1;
	int len1{ static_cast<int>(temp1.length()) };

	std::string temp2; 
	std::cout << "2 Number: ";
	std::cin >> temp2;
	int len2{ static_cast<int>(temp2.length()) };

	int* num1 = new int[len1];
	for (int i{ 0 }; i < len1; ++i) {
		num1[i] = temp1[i] - '0';
	}
	std::reverse(num1, num1 + len1);
	printNumber(num1, len1);
	std::cout << '\n';

	int* num2 = new int[len2];
	for (int i{ 0 }; i < len2; ++i) {
		num2[i] = temp2[i] - '0';
	}
	std::reverse(num2, num2 + len2);
	printNumber(num2, len2);
	std::cout << "\n+ = ";

	int* addition = addNumbers(num1, num2, len1, len2);
	printNumber(addition, std::max(len1,len2) + 1);
	std::cout << "\n- = ";

	int* subtraction;
	if (greater(num1, num2, len1,len2)) {
		subtraction = subractNumbers(num1, num2, len1, len2);
		printNumber(subtraction, std::max(len1,len2));
	}
	else {
		subtraction = subractNumbers(num2, num1, len2, len1);
		printNumber(subtraction, std::max(len1,len2), '-');
	}


	delete[] num1;
	delete[] num2;
	delete[] addition;
	delete[] subtraction;

	return 0;
}