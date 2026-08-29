class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        // Track characters in both strings
        for (int i = 0; i < s.size(); ++i) {
            // Track s string
            if (sMap.contains(s[i])) {
                ++sMap[s[i]];
            }
            else {
                sMap[s[i]] = 1;
            }

            // Track t string
            if (tMap.contains(t[i])) {
                ++tMap[t[i]];
            }
            else {
                tMap[t[i]] = 1;
            }
        }

        // Final verdict
        for (const auto& [key, value] : sMap) {
            if (tMap.contains(key)) {
                if (tMap[key] != value) {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return true;
    }
};
