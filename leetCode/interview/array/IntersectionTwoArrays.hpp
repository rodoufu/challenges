class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mnums1;
        for (auto it = nums1.begin(); it != nums1.end(); ++it) {
            if (mnums1.find(*it) == mnums1.end()) {
                mnums1.emplace(*it, 1);
            } else {
                mnums1[*it] += 1;
            }
        }
        map<int, int> mnums2;
        for (auto it = nums2.begin(); it != nums2.end(); ++it) {
            if (mnums2.find(*it) == mnums2.end()) {
                mnums2.emplace(*it, 1);
            } else {
                mnums2[*it] += 1;
            }
        }
        vector<int> resp;
        for (auto it = mnums1.begin(); it != mnums1.end(); ++it) {
            if (mnums2.find(it->first) != mnums2.end()) {
                int cont = min(it->second, mnums2[it->first]);
                resp.insert(resp.begin(), cont, it->first);
            }
        }
        return resp;
    }
};
