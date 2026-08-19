class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Number of elements not equal to val

        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == val) {
                it = nums.erase(it);
            } 
            else {
                ++it;
                ++k;
            }
        }

        return k;
    }
};