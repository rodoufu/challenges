// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<tuple<int, int, int>> valIndex;
        int len = nums.size();
        int last = nums[0];
        for (int i = 0; i < len; ++i) {
            last = min(last, nums[i]);
            valIndex.push_back(make_tuple(nums[i], i, 0));
        }
        --last;
        std::sort(std::begin(valIndex), std::end(valIndex), [](auto& a, auto& b) { return get<0>(a) < get<0>(b); });
        
        int val = 0;
        int lVal = 0;
        for (auto &[v, i, c] : valIndex) {
            if (v == last) {
                c = lVal;
            } else {
                c = val - (val && (v == last));    
            }
            ++val;
            //printf("%d:%d:%d, ", v, i, c);
            last = v;
            lVal = c;
        }
        //puts("");
        
        std::sort(std::begin(valIndex), std::end(valIndex), [](auto& a, auto& b) { return get<1>(a) < get<1>(b); });
        
        vector<int> resp;
        for (auto &x : valIndex) {
            resp.push_back(get<2>(x));
        }
        return resp;
    }
};
