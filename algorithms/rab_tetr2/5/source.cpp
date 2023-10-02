#include <iostream>
#include <ctime>

int generateNumber()
{
    int result{0};
    for(int i{0}; i < 5; ++i)
    {
        result *= 10;
        result += rand() % 10;
    }
    return result;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int sequence[10];

    std::cout << "10 чисел фон Неймана:\n";

    for(int i{0}; i < 10; ++i)
    {
        int number{};
        do {
            number = generateNumber();
        } while(number < 10000 || number > 99999);

        sequence[i] = number;
        std::cout << sequence[i] << ' ';
    }


    return 0;
}