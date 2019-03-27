// https://leetcode.com/problems/find-common-characters/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int countLetters[2][26];
        for (int i = 0; i < 26; ++i) {
            countLetters[0][i] = 0;
            countLetters[1][i] = 0;
        }
        bool iniciar = true;
        for (auto &x : A) {
            for (int i = 0; i < 26; ++i) {
                countLetters[1][i] = 0;
            }
            if (iniciar) {
                for (auto &x : x) {
                    ++countLetters[0][x - 'a'];
                }
            } else {
                for (auto &x : x) {
                    ++countLetters[1][x - 'a'];
                }

                for (int i = 0; i < 26; ++i) {
                    countLetters[0][i] = min(countLetters[0][i], countLetters[1][i]);
                }
            }
            iniciar = false;
        }
        
        vector<string> resp;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < countLetters[0][i]; ++j) {
                resp.push_back(string(1, 'a' + i));
            }
        }
        
        return resp;
    }
};
