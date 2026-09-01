class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        // Get the max subarray for the fixed array
        int maxSum = nums[0];
        int currSum = 0;

        for (const int num : nums) {
            totalSum += num; // Track total
            currSum = max(num, currSum + num);
            maxSum = max(maxSum, currSum);
        }

        // Get the min subarray for the fixed array
        int minSum = nums[0];
        currSum = 0;

        for (const int num : nums) {
            currSum = min(num, currSum + num);
            minSum = min(minSum, currSum);
        }

        // All Negative
        if (maxSum < 0) {
            return maxSum;
        }

        // Max - min is the wrapped subarray. Compare fixed vs wrapped
        return max(maxSum, (totalSum - minSum));
    }
};