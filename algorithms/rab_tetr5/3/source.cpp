#include <iostream>
#include <cmath>

double f(double x) // вычисляем значение f(x)
{
	return (exp(x - 1) - std::pow(x, 3) - x);
}

double binary_search(double a, double b, const double epsilon)
{
	if (b - a <= epsilon)
		return (a + b) / 2;
	else
	{
		double c = (a + b) / 2;

		if (f(c) * f(b) < 0)
			return binary_search(c, b, epsilon);
		else
			return binary_search(a, c, epsilon);
	}
}

int main()
{
	const double epsilon{ 1e-5 };
	double a{ 0 };
	double b{ 1 };

	std::cout << binary_search(a, b, epsilon) << '\n';
	return 0;
}
