//https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        map<char, char> openCloser = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        int len = s.length();
        const char* cs = s.c_str();
        for (int i = 0; i < len; ++i) {
            if (openCloser.find(cs[i]) != openCloser.end()) {
                mystack.push(cs[i]);
            } else {
                if (mystack.size() == 0 || cs[i] != openCloser[mystack.top()]) {
                    return false;
                }
                mystack.pop();
            }
        }
        return mystack.size() == 0;
    }
};
