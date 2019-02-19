class Solution {
public:
    vector<string> split(string str, string separator) {
        char * str_cstr = (char *) str.c_str();
        const char * delimiters = separator.c_str();
        char * it = strtok(str_cstr, delimiters);
        vector<string> resp;
        while (it) {
            resp.push_back(string(it));
            it = strtok(NULL, delimiters);
        }
        return resp;
    }

    bool wordPattern(string pattern, string str) {
        const char * pattern_c = pattern.c_str();
        vector<string> words = split(str, " ");
        int len = pattern.length();
        if (len != words.size()) {
            return false;
        }
        map<char, string> letterWord;
        map<string, char> wordLetter;
        for (int i = 0; i < len; ++i) {
            auto it = letterWord.find(pattern_c[i]);
            auto itWord = wordLetter.find(words[i]);
            if (it == letterWord.end() && itWord == wordLetter.end()) {
                letterWord[pattern_c[i]] = words[i];
                wordLetter[words[i]] = pattern_c[i];
            } else if ((it != letterWord.end() && it->second != words[i])
                    || (itWord != wordLetter.end() && itWord->second != pattern_c[i])) {
                return false;
            }
        }
        return true;
    }
};
