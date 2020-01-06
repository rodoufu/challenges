// https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m,a;
        m=a=0;
        for (auto &x :nums){
            if (x) ++a; else a =0;
            if (a>m) m=a;
        }
        return m;
    }
};
