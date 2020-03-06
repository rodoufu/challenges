// https://leetcode.com/problems/duplicate-zeros
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size(), i =0;
        for (auto it=arr.begin(); it!=arr.end() && i<len; ++it){
            if (*it == 0) {
                ++it;
                ++i;
                it = arr.insert(it, 0);
            }
            ++i;
        }
        arr.resize(len);
    }
};
