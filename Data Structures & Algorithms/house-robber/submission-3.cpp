class Solution {
private:
    unordered_map<int,int> m_cash;

    int choice(const vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }
        if (m_cash.contains(index)) {
            return m_cash[index];
        }

        m_cash[index] = max(nums[index] + choice(nums,index+2),choice(nums,index+1));
        
        return m_cash[index];
    }

public:
    int rob(vector<int>& nums) {
        return choice(nums,0);
    }
};
