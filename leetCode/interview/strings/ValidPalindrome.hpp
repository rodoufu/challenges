class Solution {
public:
    bool isPalindrome(string s) {
        std::locale loc;
        int size = s.length();
        for (int i = 0; i < size; i++) {
            s[i] = toupper(s[i]);
        }
        int ini = 0;
        int end = size - 1;
        while (ini < end) {
            while (ini < end && !isalnum(s[ini])) {
                ++ini;
            }
            while (ini < end && !isalnum(s[end])) {
                --end;
            }
            if (ini >= end) {
                break;
            }
            if (s[ini] != s[end]) {
                return false;
            }
            ++ini;
            --end;
        }
        return true;
    }
};
