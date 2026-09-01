class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currNum = nums[0];
        int maxNum = nums[0];
        int size = static_cast<int>(nums.size());

        for (int i = 1; i < size; ++i) {
            currNum = max(nums[i], currNum + nums[i]);
            maxNum = max(maxNum, currNum);
        }

        return maxNum;
    }
};
