// https://leetcode.com/problems/defanging-an-ip-address/
class Solution {
public:
    string defangIPaddr(string address) {
        string resp;
        for (auto &x : address) {
            if (x == '.') {
                resp += "[.]";
            } else {
                resp.push_back(x);
            }
        }
        
        return resp;
    }
};
