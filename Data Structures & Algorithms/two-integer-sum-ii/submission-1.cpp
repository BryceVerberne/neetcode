class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = static_cast<int>(numbers.size()) - 1;

        while (L < R) {
            int total = numbers[L] + numbers[R];
            if (total > target) {
                --R;
            }
            else if (total < target) {
                ++L;
            }
            else {
                return {L+1, R+1};
            }
        }

        return {0,0};
    }
};
