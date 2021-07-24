//https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     vector<int> left(nums.size()), right(nums.size());
     left[0] = nums[0];
     right[nums.size() - 1] = nums[nums.size() - 1];
     for(int i = 1; i < nums.size(); i++)
        left[i] = nums[i] * left[i - 1];
     for(int i = nums.size() - 2; i >= 0; i--)
        right[i] = nums[i] * right[i + 1];
     vector<int> answer(nums.size());
     answer[0] = right[1];
     for(int i = 1; i < nums.size() - 1; i++)
         answer[i] = left[i - 1] * right[i + 1];
     answer[nums.size() - 1] = left[nums.size() - 2];

    return answer;
    }
};
