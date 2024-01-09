#include <iostream>
#include <vector>

/**
 * Question from LeetCode - "Move Zeros"
 * 
 * Given an integer array nums, move all 0's to the end of it 
 * while maintaining the relative order of the non-zero elements.
 * 
 * 
 * Note that you must do this in-place without making a copy of the array
*/

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        // Use two-pointers 'non_zero_index' & 'i' to iterate through the vector
        int non_zero_index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                // std::swap is used to move the non-zero integers to the front of the vector
                std::swap(nums[i], nums[non_zero_index]); 
                non_zero_index++;
            }
        }

        for (auto elem : nums) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;
    std::vector<int> nums{0,1,0,3,6,7};
    std::vector<int> nums1{0,0,0,1,0,0};
    std::vector<int> nums2{0,0,0,0,0,7};
    std::vector<int> nums3{21,1,19,3,6,7};
    s.moveZeroes(nums);
    s.moveZeroes(nums1);
    s.moveZeroes(nums2);
    s.moveZeroes(nums3);
}