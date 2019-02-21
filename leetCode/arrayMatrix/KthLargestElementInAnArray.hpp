//https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<int> > heapq;
        int cont = 0;
        for (auto x : nums) {
            heapq.emplace(x);
            if (cont++ >= k) {
                heapq.pop();
            }
        }
        return heapq.top();
    }
};
