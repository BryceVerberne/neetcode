class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (const auto& num : nums) {
            if (set.count(num)) {
                return true;
            }
            else {
                set.insert(num);
            }
        }

        return false;
    }
};