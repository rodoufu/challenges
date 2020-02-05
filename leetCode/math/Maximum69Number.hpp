// https://leetcode.com/problems/maximum-69-number/
class Solution {
public:
    int maximum69Number (int num) {
        int mult = 1;
        int max_num = num;
        
        while (mult < num) {
            int digit = num / mult % 10;
            max_num = max(num - digit * mult + 9 * mult, max_num);
            mult *= 10;
        }
        
        return max_num;
    }
};
