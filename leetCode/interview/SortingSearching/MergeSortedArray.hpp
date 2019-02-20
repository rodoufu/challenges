//https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m + n; ++i) {
            nums1[i] = INT_MAX;
        }
        auto it1 = nums1.begin(), it2 = nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 <= *it2) {
                ++it1;
            } else {
                it1 = nums1.insert(it1, *it2);
                ++it2;
            }
        }
        nums1.resize(n + m);
    }
};
