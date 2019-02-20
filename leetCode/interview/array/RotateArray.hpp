//https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (nums.size() <= 1 || k == 0) {
            return;
        }
        k = nums.size() - k;
        vector<int>::iterator first = nums.begin();
        vector<int>::iterator middle = nums.begin() + k;
        vector<int>::iterator next = middle;
        vector<int>::iterator last = nums.end();
        while (first != next) {
            swap(*first++, *next++);
            if (next == last) {
                next = middle;
            } else if (first == middle) {
                middle = next;
            }
        }
    }
};
