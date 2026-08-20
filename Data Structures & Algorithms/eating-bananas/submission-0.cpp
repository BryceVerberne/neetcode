class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Find a viable rate
        int low = 1;
        int high = getMax(piles);;
        int lastRate = high;

        while (low <= high) {
            int m = low + (high - low) / 2;
            bool viable = possibleMin(piles, m, h);

            if (viable) {
                lastRate = m;
                high = m - 1;
            }
            else {
                low = m + 1;
            }
        }

        return lastRate;
    }

private:
    // Calculate the number of hours for a given rate
    bool possibleMin(vector<int>& piles, int rate, int h) {
        int hours = 0;

        for(const auto& pile : piles) {
            hours += (pile / rate) + ((pile % rate) != 0);

            if (hours > h) {
                return false;
            }
        }

        return true;
    }

    int getMax(vector<int>& piles) {
        int max = piles[0];

        for (const auto& pile : piles) {
            if (pile > max) {
                max = pile;
            }
        }

        return max;
    }
};
