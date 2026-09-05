class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations = {{}}; // Important! Start off the list

        // Note: ex. [1,2,3]
        //  - index 0 is the base case. This starts us off.
        //  - index 1 is the first permutation.
        //  - index 2 is the permutation built off the permutation 1.
        for (const int num : nums) { // Go through each number
            vector<vector<int>> expansion;
            
            for (const auto perm : permutations) { // Iterate through all current permutations
                for (int i = 0; i <= perm.size(); ++i) { // Insert additional num into current list
                    vector<int> newArr(perm); // Copy for editing
                    newArr.insert(newArr.begin() + i, num); // Insert our current index into our list
                    expansion.emplace_back(newArr);
                }
            }

            permutations = expansion;
        }

        return permutations;
    }
};
