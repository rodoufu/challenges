//https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> valueIndex;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (valueIndex.find(nums[i]) != valueIndex.end()) {
                valueIndex[nums[i]].push_back(i);
            } else {
                valueIndex.emplace(nums[i], vector<int>({i}));
            }
        }
        
        for (auto it = valueIndex.begin(); it != valueIndex.end(); ++it) {
            if (it->second.size() > 1) {
                auto indexes = it->second;
                int size = indexes.size();
                for (int i = 0; i < size; ++i) {
                    for (int j = i + 1; j < size; ++j) {
                        if (abs(indexes[i] - indexes[j]) <= k) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
