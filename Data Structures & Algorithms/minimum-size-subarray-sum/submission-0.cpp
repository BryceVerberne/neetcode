class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int longest = nums.size() + 1;
        int sum = 0;
        int L = 0;

        for (int R = 0; R < nums.size(); ++R) {
            sum += nums[R];

            while (sum >= target) {
                longest = min(longest, R - L + 1);
                sum -= nums[L];
                ++L;
            }
        }

        return (longest == nums.size() + 1) ? 0 : longest;
    }
};