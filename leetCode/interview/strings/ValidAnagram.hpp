//https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> counter;
        char * cs = (char *)s.c_str();
        int size = s.length();
        for (int i = 0; i < size; i++) {
            if (counter.find(cs[i]) == counter.end()) {
                counter[cs[i]] = 1;
            } else {
                counter[cs[i]] += 1;
            }
        }
        cs = (char *)t.c_str();
        size = t.length();
        for (int i = 0; i < size; i++) {
            if (counter.find(cs[i]) == counter.end()) {
                counter[cs[i]] = 1;
            } else {
                counter[cs[i]] -= 1;
            }
        }
        for (map<char,int>::iterator it = counter.begin(); it != counter.end(); ++it) {
            if (it->second != 0) {
                return false;
            }
        }
        return true;
    }
};
