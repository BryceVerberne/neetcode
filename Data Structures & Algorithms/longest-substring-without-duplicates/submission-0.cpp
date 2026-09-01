class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> catalog;
        int longest = 0;
        int L = 0;

        for (int R = 0; R < s.size(); ++R) {
            while (catalog.contains(s[R])) {
                catalog.erase(s[L]);
                ++L;
            }
            longest = max(longest, R - L + 1);
            catalog.insert(s[R]);
        }   

        return longest;
    }
};
