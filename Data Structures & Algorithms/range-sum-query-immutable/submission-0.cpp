class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        int sum = 0;

        for (const auto num : nums) {
            sum += num;
            prefix.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int rSum = prefix[right];
        int lSum = (0 > (left - 1)) ? 0 : prefix[left - 1];
        return (rSum - lSum);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */