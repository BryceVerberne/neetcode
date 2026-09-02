class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        vector<int> result(2);
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
                result = {L+1,R+1};
                break;
            }
        }

        return result;
    }
};
