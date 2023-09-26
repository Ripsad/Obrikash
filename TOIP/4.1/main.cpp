#include <iostream>

int main()
{
	std::string string1, string2;
	std::cin >> string1 >> string2;

	if(string2.length() > string1.length()) {
		std::cout << "no\n";
		return 0;
	}

	for(int i{0}; i < string1.length(); ++i) {
		std::string temp{string1[i]};
		for(int j{i + 1}; j < string1.length(); ++j) {
			if(temp.length() < string2.length())
				temp += string1[j];
			else
				break;
		
		}
		if(temp == string2) {std::cout << "yes\n"; return 0;}
	}
	std::cout << "no\n"; return 0;
}
