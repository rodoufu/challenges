class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        bool removeSize = size % 2 == 0;
        for (auto it = nums.begin(), endIt = nums.end(); it != endIt; ++it) {
            sum += (size + 1) / 2 - *it;
        }
        sum += removeSize ? (size + 1) / 2 : 0;
        return sum;
    }
};
