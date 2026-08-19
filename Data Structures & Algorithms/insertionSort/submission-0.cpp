// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        std::vector<std::vector<Pair>> output;
        
        for (int i = 0; i < pairs.size(); ++i) {
            int j = i-1;

            while((j >= 0) && (pairs[j].key > pairs[j+1].key)) {
                // Swap
                Pair tmp = pairs[j+1];
                pairs[j+1] = pairs[j];
                pairs[j] = tmp;

                // Decrement pointer (In preparation for following op)
                j -= 1;
            }

            // Save the state of the current vector
            output.push_back(pairs);
        }

        return output;
    }
};
