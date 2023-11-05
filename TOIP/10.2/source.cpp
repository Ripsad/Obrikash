#include <iostream>

int main()
{
    int len{};
    std::cin >> len;

    double* arr{ new double[len] };
    
    for(int i{0}; i < len; ++i)
        arr[i] = i+1;

    int sum{};
    for(int i{0}; i < len; ++i)
        sum += arr[i];
    
    std::cout << sum;
    delete[] arr;
    
    return 0;
}