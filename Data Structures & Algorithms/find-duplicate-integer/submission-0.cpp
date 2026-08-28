class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> tracker;

        for (const int& num : nums) {
            if (!tracker.contains(num)) {
                tracker[num] = 1;
            }
            else {
                return num;
            }
        }
    }
};
