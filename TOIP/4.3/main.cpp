#include <iostream>
#include <fstream>
int main()
{
    std::ifstream inputFile("input.txt"); 
    std::ofstream outputFile("output.txt");

    std::string string{};
    std::getline(inputFile, string);
    inputFile.close();
    std::string resultString;
    for(int i{0}; i < string.length(); ++i) {
        switch(string[i])
        {
            case '2':
                resultString += "10";
                break;
            case '3':
                resultString += "11";
                break;
            case '4':
                resultString += "100";
                break;
            case '5':
                resultString += "101";
                break;
            case '6':
                resultString += "110";
                break;
            case '7':
                resultString += "111";
                break;
            case '8':
                resultString += "1000";
                break;
            case '9':
                resultString += "1001";
                break;
            default:
                resultString += string[i];
                break;
        }
    }
    
    outputFile << resultString;
    return 0;
     
}