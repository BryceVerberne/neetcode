class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> count;

        for (const char letter : s) {
            count[letter - 'a']++;
        }
        for (const char letter : t) {
            count[letter - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};