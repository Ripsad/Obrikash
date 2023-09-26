#include <iostream>

std::string generateString(int x, int n)
{   
    std::string string{std::to_string(x)};               // наша начальная последовательность
    for(int i{1}; i < n; ++i) {
        std::string currentElement{string};              // текущий элемент последовательности
        string = "";                                     // новая последовательность
        char digit{currentElement[0]};                   // текущая цифра
        int count{1};

        for(int j{1}; j < currentElement.length(); ++j) {
            if(currentElement[j] == digit)               // считаем цифры идущие подряд
                ++count;
            else {
                string += std::to_string(count) + digit; // переходим к следующей цифре
                digit = currentElement[j];
                count = 1;                               // и обновляем счетчик цифр.
            }
        }
        string += std::to_string(count) + digit;
    }

    return string;
}

int main()
{
    int x, n;
    std::cin >> x >> n;

    std::string result{generateString(x,n)};
    std::cout << result << '\n';
    return 0;
}