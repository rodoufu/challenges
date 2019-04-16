// https://leetcode.com/problems/range-sum-query-mutable/
# define PRINT(X, Y) { \
    printf("%s - ", (Y)); \
    for (auto __it_ = (X).begin(); __it_ != (X).end(); ++__it_) { \
        printf("%2d ", *__it_); \
    } \
    putchar('\n'); \
}
class NumArray {
private:
    vector<int> preffixSum;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        int last = 0;
        preffixSum.push_back(last);
        for (auto &x : nums) {
            last += x;
            preffixSum.push_back(last);
        }
        this->nums = nums;
    }
    
    void update(int i, int val) {
        //PRINT(preffixSum, "prefS");
        //PRINT(nums, "nums   ");
        if (nums[i] != val) {
            nums[i] = val;
            int last = i > 0 ? preffixSum[i] : 0;
            auto size = nums.size();
            for (int j = i; j < size; ++j) {
                last += nums[j];
                preffixSum[j + 1] = last;
            }
        }
        //PRINT(preffixSum, "prefS");
        //PRINT(nums, "nums   ");
    }
    
    int sumRange(int i, int j) {
        return preffixSum[j + 1] - preffixSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
