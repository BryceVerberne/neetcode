class Solution {
private:
    unordered_map<int,int> m_cache;

public:
    int climbStairs(int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }
        if (m_cache.contains(n)) {
            return m_cache[n];
        }
        
        int count = 0;
        count += climbStairs(n-1);
        count += climbStairs(n-2);
        m_cache[n] = count;

        return count;
    }
};
