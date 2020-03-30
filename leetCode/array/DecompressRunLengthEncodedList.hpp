// https://leetcode.com/problems/decompress-run-length-encoded-list/
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> resp;
        int len = nums.size();
        for (int i = 0; i < len; i += 2) {
            for (int j = 0; j < nums[i]; ++j) {
                resp.push_back(nums[i + 1]);
            }
        }
        
        return resp;
    }
};
