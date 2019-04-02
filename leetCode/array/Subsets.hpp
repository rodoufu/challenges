// https://leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> resp;
        int size = nums.size();
        vector<bool> index(size, false);
        auto all_true = [](const vector<bool> & values) {
            bool resp = true;
            for (auto it = values.begin(); it != values.end(); ++it) {
                if (!resp) {
                    break;
                }
                resp &= *it;
            }
            return resp;
        };
        auto inc_true = [size](vector<bool> & values) {
            bool vaiUm = true;
            int count = 0;
            while (vaiUm && count < size) {
                vaiUm = values[count];
                values[count] = !values[count];
                ++count;
            }
        };
        auto create_vector = [&nums, size](vector<bool> & values) {
            vector<int> actual;
            for (int i = 0; i < size; ++i) {
                if (values[i]) {
                    actual.push_back(nums[i]);
                }
            }
            return actual;
        };
        
        while (!all_true(index)) {
            vector<int> actual;
            for (int i = 0; i < size; ++i) {
                if (index[i]) {
                    actual.push_back(nums[i]);
                }
            }
            resp.push_back(create_vector(index));
            inc_true(index);
        }
        resp.push_back(create_vector(index));

        return resp;
    }
};
