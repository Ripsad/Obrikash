#include <iostream>
#include <vector>
#include <algorithm>

struct Friend
{
    std::string name;
    std::string surname;
    double grade;
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<Friend> friends(n);
    for(int i{0}; i < n; ++i)
    {
        int temp1,temp2,temp3;
        std::cin >> friends[i].name >> friends[i].surname >> temp1 >> temp2 >> temp3;
        friends[i].grade = (temp1 + temp2 + temp3) / 3;
    }
    std::sort(friends.begin(), friends.end(), [](const Friend& drug1, const Friend& drug2) {
        return (drug1.grade > drug2.grade);
    });
    for(const Friend& drug : friends) {
        std::cout << drug.name << ' ' << drug.surname << '\n';
    }
    
    return 0;
}