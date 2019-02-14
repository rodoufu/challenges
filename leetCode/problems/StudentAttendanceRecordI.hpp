class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int late = 1;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if ((*it == 'A' && ++absent == 2)
                || (it != s.begin() && *it == 'L' && *(it - 1) == 'L' && ++late == 3)) {
                return false;
            } else if (*it != 'L') {
                late = 1;
            }
        }
        return true;
    }
};
