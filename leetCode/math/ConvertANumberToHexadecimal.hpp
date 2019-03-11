// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
class Solution {
public:
    string toHex(int num) {
        string resp;
        bool negative = num < 0;
        //num = negative ?  : num;
        while (num && num != -1) {
            //printf("%d\n", num);
            auto value = num & 0xf;
            if (value < 10) {
                resp = (char)('0' + value) + resp;
            } else {
                resp = (char)(value - 10 + 'a') + resp;
            }
            num >>= 4;
        }
        for (int i = resp.length(); i < 8 && negative; ++i) {
            resp = "f" + resp;
        }
        
        if (resp.empty()) {
            resp = "0";
        }
        return resp;
    }
};
