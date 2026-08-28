class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (int i = 0; i < s.size(); ++i) {
            if (!sMap.contains(s[i])) {
                sMap[s[i]] = 1;
            }
            else {
                ++sMap[s[i]];
            }
            if (!tMap.contains(t[i])) {
                tMap[t[i]] = 1;
            }
            else {
                ++tMap[t[i]];
            }
        }

        for (const auto& [key, value] : sMap) {
            if (tMap.contains(key)) {
                if (value != tMap[key]) {
                    return false;
                }
                else {
                    continue;
                }
            }
            else {
                return false;
            }
        }

        return true;
    }
};
