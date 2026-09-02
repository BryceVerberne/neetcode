class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxTurbulence = 0;
        bool k = true; // Even 
        int L = 0;

        for (int R = 0; R < arr.size(); ++R) {
            int window = R - L + 1;

            if (window > 2) {
                if (k) { // Check it is even
                    if (arr[R-1] < arr[R]) {
                        k = false;
                    }
                    else if (arr[R-1] > arr[R]) {
                        L = R-1;
                        continue;
                    }
                    else {
                        L = R;
                        continue;
                    }
                }
                else { // Check it is odd
                    if (arr[R-1] > arr[R]) {
                        k = true;
                    }
                    else if (arr[R-1] < arr[R]) {
                        L = R-1;
                        continue;
                    }
                    else {
                        L = R;
                        continue;
                    }
                }
            }
            
            if (window == 2) {
                // Set odd/even 
                if (arr[R-1] < arr[R]) {
                    k = false;
                }
                else if (arr[R-1] > arr[R]) {
                    k = true;
                }
                else {
                    L = R;
                    continue;
                }
            }

            maxTurbulence = max(maxTurbulence, window);
        }

        return maxTurbulence;
    }
};