class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int res;

        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            res = x - y;
            if (res > 0) {
                pq.push(res);
            }
        }

        return (pq.empty()) ? 0 : pq.top();
    }
};
