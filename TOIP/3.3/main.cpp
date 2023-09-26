#include <iostream>

int main()
{
    /* получаем матрицу, количество грибов(используем unsigned integer
    так как числа все неотрицательные и имеют малые значения) */ 

    int rows{};
    int cols{};
    std::cin >> rows >> cols;
    int mushrooms{};
    std::cin >> mushrooms;

    // создаем и получаем пары координат расположений грибов

    // int** pairs = new int*[mushrooms];
    // for(int i{0}; i < mushrooms; ++i) {
    //     pairs[i] = new int[2];
    // }

    // for(int i{0}; i < mushrooms; ++i) {
    //     std::cin >> pairs[i][0] >> pairs[i][1];
    // }

    // наше грибное поле.

    char** matrix = new char*[rows];
    for(int i{0}; i < rows; ++i) {
        matrix[i] = new char[cols];
    }

    for(int i{0}; i < mushrooms; ++i) {
        int x,y;
        std::cin >> x >> y;

        matrix[x - 1][y - 1] = '*';
    }

    for(int i{0}; i < rows; ++i) {
        for(int j{0}; j < cols; ++j) {
            if(matrix[i][j] == '*')
                continue;
            int count{0};
            if(i+1 < rows && matrix[i+1][j] == '*' )
                ++count;
            if(j + 1 < cols && matrix[i][j+1] == '*')
                ++count;
            if(j + 1 < cols && i + 1 << rows && matrix[i+1][j+1] == '*')
                ++count;
            if(j + 1 < cols && i - 1 > rows && matrix[i-1][j + 1] == '*')
                ++count;
            if(i - 1 > rows && matrix[i-1][j] == '*')
                ++count;
            if(j - 1 > cols && matrix[i-1][j-1] == '*' && i - 1 > rows &&)
                ++count;
            if(j > cols && matrix[i][j-1] == '*')
                ++count;
            if(i < rows && j > cols && matrix[i+1][j-1] == '*')
                ++count;
            if(i < rows && matrix[i+1][j] == '*')
                ++count;
            matrix[i][j] == static_cast<char>(count);
        }
    }

    for(int i{0}; i < rows; ++i) {
        for(int j{0}; j < cols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }


    // возвращаем всю взятую память операционке.

    for(int i{0}; i < rows; ++i) {
        delete[] matrix[i];
    }

    // for(int i{0}; i < mushrooms; ++i) {
    //     delete[] pairs[i];
    // }

    // delete[] pairs;
    delete[] matrix;
    return 0;
}