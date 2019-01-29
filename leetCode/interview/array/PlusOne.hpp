class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool plus = true;
        vector<int> resp;
        int value;
        for (auto it = digits.rbegin(); it!= digits.rend(); ++it) {
            value = *it + (plus ? 1 : 0);
            plus = value > 9;
            value %= 10;
            resp.push_back(value);
        }
        if (plus) {
            resp.push_back(1);
        }
        reverse(resp.begin(), resp.end());
        return resp;
    }
};
