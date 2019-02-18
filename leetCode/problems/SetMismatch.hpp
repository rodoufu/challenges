class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> numsSet;
        int size = nums.size();
        for (int i = 1; i <= size; ++i) {
            numsSet.insert(i);
        }
        int repeated = -1;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (numsSet.find(*it) == numsSet.end()) {
                repeated = *it;
            }
            numsSet.erase(*it);
        }

        vector<int> resp;
        resp.push_back(repeated);
        resp.insert(resp.end(), numsSet.begin(), numsSet.end());
        return resp;
    }
};
