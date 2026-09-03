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

        int first = nums[index] + choice(nums,index+2);
        int second = choice(nums,index+1);
        m_cash[index] = max(first,second);
        
        return m_cash[index];
    }

public:
    int rob(vector<int>& nums) {
        return choice(nums,0);
    }
};
