class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> letters;
        const char * word = s.c_str();
        int size = s.length();
        for (int i = 0; i < size; ++i) {
            if (letters.find(word[i]) == letters.end()) {
                letters[word[i]] = i;
            } else {
                letters[word[i]] = size;
            }
        }
        int resp = size;
        for (map<char,int>::iterator it = letters.begin(); it != letters.end(); ++it) {
            resp = resp < it->second ? resp : it->second;
        }
        return resp == size ? -1 : resp;
    }
};
