// https://leetcode.com/problems/number-of-lines-to-write-string/
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 0;
        int last = 0;
        for (auto x : S) {
            if (last + widths[x - 'a'] > 100) {
                ++lines;
                last = widths[x - 'a'];
            } else {
                last += widths[x - 'a'];
            }
            //printf("%d,%d\n", lines, last);
        }
        return vector<int>({last > 0 ? lines + 1 : lines, last});
    }
};
