class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int sum = 0;
        int L = 0;

        for (int R = 0; R < arr.size(); ++R) {
            int window = R - L + 1;
            sum += arr[R];

            if (window > k) {
                sum -= arr[L];
                ++L;
                --window;
            }
            if ((window == k) && ((sum / k) >= threshold)) { 
                ++count;
            } 
        }

        return count;
    }
};