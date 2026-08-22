class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        int mid;
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }

        return left;
    }
};