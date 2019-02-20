//https://leetcode.com/problems/count-and-say/
class Solution {
public:
    string countToSay(string &num) {
        string resp;
        int lennum = num.length();
        const char * numc = num.c_str();
        char letter = 0;
        int count = 0;
        for (int i = 0; i < lennum; i++) {
            if (letter == numc[i]) {
                ++count;
            } else {
                if (letter) {
                    resp += to_string(count);
                    resp += letter;
                }
                letter = numc[i];
                count = 1;
            }
        }
        if (letter) {
            resp += to_string(count);
            resp += letter;
        }
        return resp;
    }
    
    string countAndSay(int n) {
        string resp = "1";
        for (int i = 1; i < n; i++) {
            resp = countToSay(resp);
        }
        return resp;
    }
};
