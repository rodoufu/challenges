class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1, set2;
        for (auto it = nums1.begin(); it != nums1.end(); ++it) {
            set1.insert(*it);
        }
        for (auto it = nums2.begin(); it != nums2.end(); ++it) {
            set2.insert(*it);
        }
        vector<int> resp;
        for (auto it = set1.begin(); it != set1.end(); ++it) {
            if (set2.find(*it) != set2.end()) {
                resp.push_back(*it);
            }
        }
        return resp;
    }
};
