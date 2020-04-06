// https://leetcode.com/problems/uncommon-words-from-two-sentences/
class Solution {
private:
    vector<string> uniqueWords(string &x) {
        unordered_map<string, int> resp;
        char *pch = strtok((char *) x.c_str(), " ");
        while (pch != nullptr) {
            auto word = string(pch);
            ++resp[word];
            pch = strtok(nullptr, " ");
        }
        vector<string> r;
        for (auto &[w, c] : resp) {
            if (c == 1) {
                r.push_back(w);
            }
        }
        return r;
    }
public:
    vector<string> uncommonFromSentences(string A, string B) {
        auto v = A + " " + B;
        return uniqueWords(v);
    }
};
