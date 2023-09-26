#include <iostream>
#include <fstream>

std::string convertToBin(int number)
{
    std::string numInBin;
     while(number > 0) {
        int remainder{number % 2};
        numInBin = std::to_string(remainder) + numInBin;
        number /= 2;
        }
    return numInBin;
}

int main()
{
    std::ifstream inputFile("input.txt"); 
    std::ofstream outputFile("output.txt");

    std::string string{};
    std::getline(inputFile, string);
    inputFile.close();
    std::string resultString;
    int number{0};
    for(int i{0}; i < string.length(); ++i) {
        switch(string[i])
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if(number) number *= 10;
                number += static_cast<int>(string[i] - '0');
                continue;
            default:
            if(!number)
                resultString += string[i];
            else {
                std::string numInBin{convertToBin(number)};
               
                resultString += numInBin;
                number = 0;
                resultString += string[i];
            }
            break;
        }
        
    }
    if(number) resultString += convertToBin(number);
    outputFile << resultString;

    return 0;
     
}