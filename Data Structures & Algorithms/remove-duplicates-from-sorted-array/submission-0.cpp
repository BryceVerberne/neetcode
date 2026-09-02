class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> catalog;
        bool duplicate = false;
        int L = 0;

        for (int R = 0; R < nums.size(); ++R) {
            if (catalog.contains(nums[R])) { // Duplicate
                duplicate = true;
            }
            else {
                catalog.insert(nums[R]);

                if (duplicate) {
                    nums[L] = nums[R];
                }

                ++L;
            }
        }

        return L;
    }
};