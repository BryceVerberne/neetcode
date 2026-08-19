class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> valid_nums1(nums1.begin(), nums1.begin() + m);  

        int i = 0;
        int j = 0;
        int k = 0;
        
        // Dah baby code
        while((valid_nums1.size() > i) && (nums2.size() > j)) {
            if (valid_nums1[i] <= nums2[j]) {
                nums1[k++] = valid_nums1[i++];
            }
            else { // nums2[j] < valid_nums1[i]
                nums1[k++] = nums2[j++];
            }
        }

        // Copy over the remaining elements
        while(valid_nums1.size() > i) {
            nums1[k++] = valid_nums1[i++];
        }
        while(nums2.size() > j) {
            nums1[k++] = nums2[j++];
        }
    }
};