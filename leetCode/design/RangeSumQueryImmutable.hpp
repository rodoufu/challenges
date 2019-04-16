// https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
private:
    vector<int> preffixSum;
public:
    NumArray(vector<int>& nums) {
        int last = 0;
        preffixSum.push_back(last);
        for (auto &x : nums) {
            last += x;
            preffixSum.push_back(last);
        }
    }
    
    int sumRange(int i, int j) {
        return preffixSum[j + 1] - preffixSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
