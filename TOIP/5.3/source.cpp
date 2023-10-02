#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
    std::string name;
    std::string surname;
    std::string klass;
    std::string dateOfBirth;
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<Student> students(n);
    for(int i{0}; i < n; ++i)
    {
        std::cin >> students[i].surname >> students[i].name >>
        students[i].klass >> students[i].dateOfBirth;
    }

    std::sort(students.begin(), students.end(), [](const Student& student1, 
    const Student& student2) {
        if(student1.klass == student2.klass)
            return student1.surname < student2.surname;
        return student1.klass < student2.klass;
    });
    
    for(const Student& student : students)
    {
        std::cout << student.klass <<
        ' ' << student.surname << ' ' << student.name << ' ' << 
        student.dateOfBirth << '\n';
    }

    return 0;
}