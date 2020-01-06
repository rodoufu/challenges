// https://leetcode.com/problems/long-pressed-name/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto ni=name.begin(), ti=typed.begin();
        while (ni != name.end() && ti != typed.end()){
            auto a = *ni;
            if (a != *ti) return false;
            ++ni;
            ++ti;
            if (ni == name.end() && ti == typed.end()) return true;
            if (ti == typed.end()) return false;
            if (*ni == a) continue;
            while (ti != typed.end() && *ti == a) ++ti;
        }
        return ni == name.end() && ti == typed.end();
    }
};
