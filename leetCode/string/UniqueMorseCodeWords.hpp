//https://leetcode.com/problems/unique-morse-code-words
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[] = {".-","-...","-.-.","-..",".","..-.",
            "--.","....","..",".---","-.-",".-..","--","-.","---",
            ".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
            "-.--","--.."
        };
        unordered_set<string> transformations;
        for (auto & word : words) {
            string transformed;
            for (auto & l : word) {
                transformed += code[l - 'a'];
            }
            transformations.emplace(transformed);
        }
        
        return transformations.size();
    }
};
