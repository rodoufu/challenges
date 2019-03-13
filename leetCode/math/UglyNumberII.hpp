// https://leetcode.com/problems/ugly-number-ii/
class Solution {
private:
    inline void mySort(vector<long long>& uglies) {
        int r = uglies.size() - 1;
        while (r && uglies[r - 1] > uglies[r]) {
            swap(uglies[r - 1], uglies[r]);
            --r;
        }
    }

    inline void printUglies(vector<long long>& uglies) {
        for (auto &x : uglies) {
            printf("%d ", x);
        }
        puts("");
    }
public:
    int nthUglyNumber(int n) {
        if (n == 0) {
            return 0;
        }
        vector<long long> uglies = {1};
        unordered_set<long long> used = {1};
        vector<long long> factors = {2, 3, 5};
        for (int i = 0; i < n; ++i) {
            if (uglies.size() >= n && uglies[i] * 2 > uglies[n - 1]) {
                break;
            }
            for (auto &x : factors) {
                if (used.find(uglies[i] * x) == used.end()) {
                    uglies.push_back(uglies[i] * x);
                    mySort(uglies);
                    //printUglies(uglies);
                    used.emplace(uglies[i] * x);
                }
            }
        }
        return (int) uglies[n - 1];
    }
};
