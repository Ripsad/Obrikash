#include <iostream>
#include <sstream>

double calculate(double a, double b) {
	return a * b;
}

double calculate(double a, double b, char operation)
{
	switch (operation)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '/':
		if (b != 0)
			return a / b;
		else
			return 0;
	case '*':
		return a * b;
	default:
		return 0;
	}
}

int main()
{
	double a, b;
	char operation;

	std::string input;
	std::getline(std::cin, input);

	for (int i{ 0 }; i < input.length(); ++i)
	{
		if (input[i] != 32)
			continue;
		else {
			a = stoi(input.substr(0, i));
			switch (input[i + 1])
			{
			case '+':
			case '-':
			case '/':
			case '*':
				operation = input[i + 1];
				b = stoi(input.substr(i + 3, input.length()));
				std::cout << calculate(a, b, operation);
				break;
			default:
				b = stoi(input.substr(i + 1, input.length()));
				std::cout << calculate(a, b);
				break;
			}
			break;
		}
	}
	
	return 0;
}