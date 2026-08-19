/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int m = low + (high - low) / 2;
            int correct = guess(m);
            
            if (correct < 0) {
                high = m - 1;
            }
            else if (correct > 0) {
                low = m + 1;
            }
            else {
                return m;
            }
        }

        return -1;
    }
};