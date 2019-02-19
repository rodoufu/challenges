class Solution {
public:
    string reverseStr(string s, int k) {
        vector<char> text(s.begin(), s.end());
        const int size = s.length();
        for (int i = 0; i < size; i += 2 * k) {
            auto it = text.begin();
            reverse(it + i, it + min(i + k, size));
        }
        return string(text.begin(), text.end());
    }
};
