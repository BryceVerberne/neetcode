class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors = {0,0,0};

        // Track number of existing colors
        for (int i = 0; i < nums.size(); ++i) {
            colors[nums[i]]++;
        }

        // Overwrite current array
        int k = 0;
        for (int i = 0; i < colors.size(); ++i) {
            for (int j = 0; j < colors[i]; ++j) {
                nums[k++] = i;
            }
        }
    }
};