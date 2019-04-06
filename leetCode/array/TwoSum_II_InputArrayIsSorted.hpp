// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, vector<int> > num_index;
        auto size = numbers.size();
        for (int i = 0; i < size; ++i) {
            if (num_index.find(numbers[i]) == num_index.end()) {
                num_index[numbers[i]] = vector<int>();
            }
            num_index[numbers[i]].push_back(i);
        }
        /*for (auto &x : num_index) {
            printf("%d: ", x.first);
            for (auto &y: x.second) {
                printf("%d ", y);
            }
            putchar('\n');
        }*/
        vector<int> resp;
        for (int i = 0; i < size; ++i) {
            if (num_index.find(target - numbers[i]) != num_index.end()) {
                resp.push_back(i + 1);
                if (target - numbers[i] == numbers[i]) {
                    resp.push_back(num_index[target - numbers[i]][1] + 1);
                } else {
                    resp.push_back(num_index[target - numbers[i]][0] + 1);
                }

                if (resp[0] > resp[1]) {
                    swap(resp[0], resp[1]);
                }
                return resp;
            }
        }
        return resp;
    }
};
