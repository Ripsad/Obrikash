#include <iostream>
#include <vector>


int findStudentsWithCompany(const std::vector<int>& vect)
{
    std::vector<int> stack;
    int count{ 0 };
    int lastStudent{0};
    for(const int& student : vect)
    {
        if(stack.empty()) {
            stack.push_back(student);
            if(student == lastStudent) {
                ++count;
                stack.pop_back();
            }
        }
        else if(stack.back() == student) {
            lastStudent = student;
            stack.pop_back();
            count += 2;
        }
        else
            stack.push_back(student);
    }
    
    if(!stack.empty())
    {
        if(vect[vect.size()-2] == stack.back()) ++count;
        return count;
    }
    else return count;
}

int main()
{
    int count{};
    std::cin >> count;
    std::vector<int> vect(count);
    for(int i{0}; i < count; ++i)
        std::cin >> vect[i];
    std::cout << findStudentsWithCompany(vect) << std::endl;
    
}