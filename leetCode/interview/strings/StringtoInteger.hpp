class Solution {
public:
    int myAtoi(string str) {
        bool negative = false;
        long long resp = 0;
        
        const char * nstr = str.c_str();
        int size = str.length();
        bool space = false;
        bool sig = false;

        for (int i = 0; i < size; ++i) {          
            if (nstr[i] == ' ') {
                if (space) {
                    break;
                }
            } else if (nstr[i] == '-' or nstr[i] == '+') {
                if (sig) {
                    break;
                }
                sig = true;
                space = true;
                negative = nstr[i] == '-';
            } else if (isdigit(nstr[i])) {
                space = true;
                sig = true;
                resp = 10 * resp + nstr[i] - '0';
            } else {
                break;
            }
            
            if (resp > INT_MAX) {
                return negative ? INT_MIN : INT_MAX;
            }
        }
        
        return negative ? -resp : resp;
    }
};
