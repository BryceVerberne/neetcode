class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        while (k > 1 && !pq.empty()) {
            pq.pop();
            --k;
        }

        return (pq.empty()) ? INT_MIN : pq.top();
    }
};
