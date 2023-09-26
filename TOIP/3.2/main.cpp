#include <iostream>

int main()
{
    int n{};
    std::cin >> n;

    int** matrix{new int*[n]};
    for(int i{0}; i < n; ++i) {
        matrix[i] = new int[n];
    }
    
    for(int rows{0}; rows < n; ++rows) {
        for(int cols{0}; cols < n; ++cols) {
            if(rows + cols + 2 == n+1)
                matrix[rows][cols] = 1;
            else if(rows+cols+2 < n + 1)
                matrix[rows][cols] = 0;
            else
                matrix[rows][cols] = 2;
        }
    }



    for(int i{0}; i < n; ++i) {
        for(int j{0}; j < n; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    for(int i{0}; i < n; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}