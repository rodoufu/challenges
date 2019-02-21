//https://leetcode.com/problems/base-7
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        bool negative = num < 0;
        long long int n = negative ? -((long long int) num) : num;
        vector<char> values;
        while (n) {
            values.push_back('0' + n % 7);
            n /= 7;
        }
        
        return (negative ? "-" : "") + string(values.rbegin(), values.rend());
    }
};
