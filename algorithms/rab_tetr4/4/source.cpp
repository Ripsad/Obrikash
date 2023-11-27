#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    std::vector<int> intersection;
    for (int num : set1) {
        if (set2.count(num)) {
            intersection.push_back(num);
        }
    }

    return intersection;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {0, 2, 4, 6, 8};
    std::vector<int> result = intersection(nums1, nums2);
    std::cout << "intersection: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
