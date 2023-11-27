#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> two_sum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hash_table;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (hash_table.find(complement) != hash_table.end()) {
            return {hash_table[complement], i};
        }
        hash_table[nums[i]] = i;
    }

    return {};
}

int main() {
    std::vector<int> nums = {-1, 2, 3, 4, 7};
    int target = 5;
    std::vector<int> result = two_sum(nums, target);
    if (!result.empty()) {
        std::cout << "Indexes: " << result[0] << ", " << result[1] << '\n';
    } else {
        std::cout << "no appropriate numbers\n";
    }
    return 0;
}
