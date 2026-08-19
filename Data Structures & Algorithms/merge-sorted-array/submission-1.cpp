class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> vnums1(nums1.begin(), nums1.begin() + m);

        int i = 0;
        int j = 0;
        int k = 0;

        // Compare up to matching length
        while ((vnums1.size() > i) && (nums2.size() > j)) {
            if (vnums1[i] <= nums2[j]) {
                nums1[k++] = vnums1[i++];
            }
            else {
                nums1[k++] = nums2[j++];
            }
        }

        // Grab all remaining values
        while (vnums1.size() > i) {
            nums1[k++] = vnums1[i++];
        }
        while (nums2.size() > j) {
            nums1[k++] = nums2[j++];
        }
    }
};