class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> catalog;
        int count = 0;
        int maxf = 0;
        int L = 0;

        for (int R = 0; R < s.size(); ++R) {
            int window = R - L + 1;

            // Add encountered character
            ++catalog[s[R]];
            maxf = max(maxf, catalog[s[R]]);

            // Ensure the window size is valid
            while (window - maxf > k) {
                --catalog[s[L]];
                --window;
                ++L;
            }

            count = max(count, window);
        }

        return count;
    }
};
