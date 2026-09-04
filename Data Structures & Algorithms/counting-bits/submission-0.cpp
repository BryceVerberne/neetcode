class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1);

        for (int i = 0; i <= n; i++) {
            int count = 0;
            int num = i;

            while (num > 0) {
                if (num & 1 == 1) ++count;
                num >>= 1;
            }

            arr[i] = count;
        }

        return arr;
    }
};
