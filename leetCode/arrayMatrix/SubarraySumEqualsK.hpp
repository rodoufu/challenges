//https://leetcode.com/problems/subarray-sum-equals-k
#define PRINT_ALL(X) printf("["); \
    for (auto __it = (X).begin(); __it != (X).end(); ++__it) { \
        printf("%d, ", *__it); \
    } \
    printf("]")

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefSum;
        prefSum.push_back(nums[0]);
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            prefSum.push_back(prefSum[i - 1] + nums[i]);
        }
        /*
        printf("prefSum:\n");
        PRINT_ALL(prefSum);
        */

        unordered_map<int, unordered_set<int> > sumIndex;
        for (int i = 0; i < size; ++i) {
            if (sumIndex.find(prefSum[i]) != sumIndex.end()) {
                sumIndex[prefSum[i]].emplace(i);
            } else {
                sumIndex[prefSum[i]] = unordered_set<int>({i});
            }
        }
        /*
        printf("\nsumIndex:\n");
        for (auto it = sumIndex.begin(); it != sumIndex.end(); ++it) {
            printf("%d: ", it->first);
            PRINT_ALL(it->second);
            putchar('\n');
        }
        */
        
        int count = 0;
        if (sumIndex.find(k) != sumIndex.end()) {
            //printf("pfS:%d\n", sumIndex[k].size());
            count += sumIndex[k].size();
        }
        for (int i = 0; i < size; ++i) {
            if (sumIndex.find(prefSum[i] - k) != sumIndex.end()) {
                auto mySet = sumIndex[prefSum[i] - k];
                for (auto it = mySet.begin(); it != mySet.end(); ++it) {
                    //printf("i:%d,it:%d\n", i, *it);
                    count += *it < i ? 1 : 0;
                }
            }
        }
        return count;
    }
};
