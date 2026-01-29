#include <iostream>
#include <vector>
#include <unordered_set>

// Sorted array version
void removeDuplicatesSortedArray(std::vector<int>& nums) {
    if (nums.empty()) return;

    size_t idx = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[idx]) {
            nums[++idx] = nums[i];
        }
    }
    nums.resize(idx + 1);
}

// Unsorted array version using unordered_set
// An unordered_set is a data structure which is different than a vector
// It does not maintain any order of elements but provides average O(1) time complexity for
// insertions, deletions, and lookups.
void removeDuplicatesUnsortedArray(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    size_t idx = 0;

    for (size_t i = 0; i < nums.size(); ++i) {
        if (seen.find(nums[i]) == seen.end()) {
            seen.insert(nums[i]);
            nums[idx++] = nums[i];
        }
    }
    nums.resize(idx);
}

int main() {
    std::vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 5, 5, 6};
    removeDuplicatesSortedArray(arr);

    std::cout << "Array after removing duplicates: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}