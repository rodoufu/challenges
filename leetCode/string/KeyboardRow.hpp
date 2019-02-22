//https://leetcode.com/problems/keyboard-row/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> line[] = {
            {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
            {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
            {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
            {'z', 'x', 'c', 'v', 'b', 'n', 'm'}
        };
        
        vector<string> resp;
        for (auto & word : words) {
            //cout << "w: " << word << endl;
            int len = word.length();
            if (len) {
                int index = -1;
                for (int i = 0; i < 4 && index == -1; ++i) {
                    if (line[i].find(word[0]) != line[i].end() || line[i].find(tolower(word[0])) != line[i].end()) {
                        index = i;
                    }
                }
                
                bool add = true;
                //printf("idx:%d\n", index);
                if (index >= 0) {
                    for (int i = 0; i < len && add; ++i) {
                        add = line[index].find(word[i]) != line[index].end() || line[index].find(tolower(word[i])) != line[index].end();
                    }
                }
                if (add) {
                    resp.push_back(word);
                }
            }
        }
        
        return resp;
    }
};
