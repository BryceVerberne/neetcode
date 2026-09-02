class Solution {
private:
    char getLargest(unordered_map<char, int>& catalog, char largest) {
        for (const auto& [key, value] : catalog) {
            if (value > catalog[largest]) {
                largest = key;
            }
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
            if (!catalog.contains(s[R])) {
                catalog[s[R]] = 1;
            }
            else {
                ++catalog[s[R]];
            }

            // Find the most encountered character
            char largest = getLargest(catalog, s[R]);

            // Ensure the window size is valid
            while (window - catalog[largest] > k) {
                --catalog[s[L]];
                largest = getLargest(catalog, s[R]);
                --window;
                ++L;
            }

            count = max(count, window);
        }

        return count;
    }
};
