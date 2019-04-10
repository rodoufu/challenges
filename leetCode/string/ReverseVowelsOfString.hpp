// https://leetcode.com/problems/reverse-vowels-of-a-string/
class Solution {
public:
    string reverseVowels(string s) {
        auto len = s.length();
        if (!len) {
            return s;
        }
        unordered_set<char> vogais = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        };
        
        for (int ini = 0, end = len - 1; ini < end; ++ini) {
            if (vogais.find(s[ini]) != vogais.end()) {
                while (ini < end && vogais.find(s[end]) == vogais.end()) {
                    --end;
                }
                if (ini < end) {
                    swap(s[ini], s[end--]);
                }
            }
        }
        
        return s;
    }
};
