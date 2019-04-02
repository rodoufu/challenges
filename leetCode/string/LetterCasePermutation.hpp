// https://leetcode.com/problems/letter-case-permutation/
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        stack<tuple<string, int> > words;
        words.push(make_tuple(S, 0));
        vector<string> resp;
        while (!words.empty()) {
            auto word_pos = words.top();
            words.pop();
            auto word = get<0>(word_pos);
            resp.push_back(word);
            int size = word.size();
            auto from = get<1>(word_pos);
            for (int i = from; i < size; ++i) {
                if (isalpha(word[i])) {
                    if (isupper(word[i])) {
                        auto new_word = word;
                        new_word[i] = tolower(word[i]);
                        words.push(make_tuple(new_word, i + 1));
                    } else {
                        auto new_word = word;
                        new_word[i] = toupper(word[i]);
                        words.push(make_tuple(new_word, i + 1));
                    }
                }
            }
        }
        return resp;
    }
};
