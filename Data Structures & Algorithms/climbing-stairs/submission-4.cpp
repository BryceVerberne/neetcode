class Solution {
public:
    int climbStairs(int n) {
        pair<int,int> cache{1,2};

        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        for (int i = 3; i <= n; ++i) {
            int tmp = cache.first + cache.second;
            cache.first = cache.second;
            cache.second = tmp;
        }

        return cache.second;
    }
};
