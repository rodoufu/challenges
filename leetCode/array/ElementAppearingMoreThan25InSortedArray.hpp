// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 0;
        int resp = arr[0];
        int len = arr.size();
        
        for (auto &x : arr) {
            if (x == resp) {
                ++count;
            } else {
                count = 0;
            }
            resp = x;
            if (static_cast<double>(count) / len > .25) {
                break;
            }
        }
        return resp;
    }
};
