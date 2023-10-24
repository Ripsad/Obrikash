#include <iostream>
#include <string>
#include <vector>

std::string big_num(int count)
{
	char* num = new char[count];
	for (int i{ 0 }; i < count; ++i)
		num[i] = (rand() % 10) + '0';

	int hnum{ 0 };
	while (true) {
		hnum = (rand() % 10) + '0';
		if (hnum != '0') break;
	}
	num[count - 1] = hnum;
    std::string result{ "" };
    for (int i{ 0 }; i < count; ++i)
        result += num[i];
	return result;
}

std::string multiplyNumbers(const std::string& num1, const std::string& num2)
{
    int len = num1.length();

    std::vector<int> result(len * 2, 0);

    for(int i = len - 1; i >= 0; i--) {
        for(int j = len - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j] += sum /10;
            result[i + j + 1] = sum % 10;
        }
    }

    int start = 0;
    while(start < result.size() - 1 && result[start] == 0) start++;

    std::string finalResult{ "" };
    for(int i = start; i < result.size(); i++) {
        finalResult += result[i] + '0';
    }
    
    return finalResult;
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

    std::string num1 = big_num(count);
    std::string num2 = big_num(count);
    std::cout << num1 << " * " << num2 << " = ";
    std::string result = multiplyNumbers(num1,num2);

    std::cout << result << '\n';


    return 0;
}