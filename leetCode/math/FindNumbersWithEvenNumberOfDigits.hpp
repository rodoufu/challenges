// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
class Solution {
private:
    inline int count(int n) {
        if (n == 0)
            return 1;
        int resp = 0;
        while (n) {
            ++resp;
            n /= 10;
        }
        return resp;
    }
public:
    int findNumbers(vector<int>& nums) {
        int r=0;
        for (auto & x : nums) {
            if (count(x) % 2 == 0)
                ++r;
        }
        return r;
    }
};
