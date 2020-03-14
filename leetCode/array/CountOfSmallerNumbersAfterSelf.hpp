// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> resp(len, 0);
        map<int, int> count;
        
        for (int i = len - 1; i >= 0; --i) {
            int val = 0;
            //printf("i:%d, n:%d, v:%d\n", i, nums[i], val);
            for (auto &[k, v]: count) {
                //printf("k:%d, v:%d ", k, v);
                if (nums[i] > k) {
                    val += v;
                } else {
                    break;
                }
            }
            resp[i] = val;
            //printf("\ni:%d, n:%d, v:%d\n", i, nums[i], val);
            ++count[nums[i]];
        }
        
        return resp;
    }
};
