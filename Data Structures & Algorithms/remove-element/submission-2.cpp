class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it != val) {
                ++k;
                ++it;
            }
            else {
                it = nums.erase(it);
            }
        }

        return k;
    }
};