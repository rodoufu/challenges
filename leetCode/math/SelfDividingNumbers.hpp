// https://leetcode.com/problems/self-dividing-numbers/
class Solution {
private:
    inline bool isSelfDividing(int num) {
        num = num > 0 ? num : -num;
        int temp = num, digit;
        
        while (temp) {
            digit = temp % 10;
            if (!digit || num % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> resp;
        
        for (int i = left; i <= right; ++i) {
            if (isSelfDividing(i)) {
                resp.push_back(i);
            }
        }
        
        return resp;
    }
};
