class Solution {
private:
    int getLargest(const unordered_map<char, int>& catalog) {
        int largest = 0;
        
        for (const auto& [key, value] : catalog) {
            largest = max(largest, value);
        }

        return largest;
    }

public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> catalog;
        int count = 0;
        int L = 0;

        for (int R = 0; R < s.size(); ++R) {
            int window = R - L + 1;

            // Add encountered character
            ++catalog[s[R]];

            // Ensure the window size is valid
            while (window - getLargest(catalog) > k) {
                --catalog[s[L]];
                --window;
                ++L;
            }

            count = max(count, window);
        }

        return count;
    }
};
