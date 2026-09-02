class Solution {
private:
    vector<int> prefix;

    void rangeSum(const vector<int>& nums) {
        int sum = 0;
        for (const int num : nums) {
            sum += num;
            prefix.push_back(sum);
        }
    }

public:
    int pivotIndex(vector<int>& nums) {
        rangeSum(nums); // Calculate the prefix sum: O(n)

        // Find the pivot
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate left
            int left = (i == 0) ? 0 : prefix[i - 1];

            // Calculate right
            int right = (i == nums.size() - 1) ? 0 : (prefix.back() - prefix[i]);

            if (left == right) {
                return i;
            }
        }
        
        return -1;
    }
};