//https://leetcode.com/problems/shuffle-an-array/
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled(nums);
        for (int i = 0, size = nums.size(); i < size; ++i) {
           swap(shuffled[i], shuffled[rand() % size]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
