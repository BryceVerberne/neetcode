class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // O(n^2) is an acceptable complexity as the arr.length < 10^5
        for (int i = 0; i < arr.size(); ++i) {
            int a = arr.at(i);
            int max = -1;

            for (int j = i+1; j < arr.size(); ++j) {
                int b = arr.at(j);
                if (max < b) max = b;
            }

            arr[i] = max;
        }

        return arr;
    }
};