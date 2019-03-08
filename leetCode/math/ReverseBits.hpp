//https://leetcode.com/problems/reverse-bits/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t resp = 0;
        uint a = 0;
        while (n) {
            resp = resp * 2 + n % 2;
            n /= 2;
            ++a;
        }
        return resp ? resp << (32 - a) : resp;
    }
};
