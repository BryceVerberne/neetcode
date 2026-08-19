class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int max = 0;

        for (const auto& num : nums) {
            if (num == 1) ++ones;
            else {
                if (ones > max) max = ones;
                ones = 0;
            }
        }
        if (ones > max) max = ones;

        return max;
    }
};