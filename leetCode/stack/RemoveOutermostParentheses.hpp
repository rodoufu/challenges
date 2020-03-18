// https://leetcode.com/problems/remove-outermost-parentheses/
class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> par;
        string resp;
        for (auto &x : S) {
            if (x == '(') {
                if (!par.empty()) {
                    resp.push_back('(');
                }
                par.emplace('(');
            } else {
                if (par.size() > 1) {
                    resp.push_back(')');
                }
                par.pop();
            }
        }
        
        return resp;
    }
};
