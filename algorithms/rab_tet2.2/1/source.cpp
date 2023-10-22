#include <iostream>

int main()
{
    int num{};
    std::cin >> num;
	if (num <= 0) { 
		std::cout << '0';
    	return 0;
        }
    bool isPower{ (num & (num - 1)) == 0 };
    if (isPower) std::cout << '1';
    else std::cout << '0';

    return 0;
}