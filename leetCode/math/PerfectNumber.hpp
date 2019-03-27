// https://leetcode.com/problems/perfect-number/
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        unordered_set<int> divisors({1});
        int to = sqrt(num) + 1;
        for (int i = 2; i < to; ++i) {
            if (num % i == 0) {
                divisors.emplace(i);
                divisors.emplace(num / i);
            }
        }
        /*for (auto & x : divisors) {
            printf("%d ", x);
        }*/
        
        return accumulate(divisors.begin(), divisors.end(), 0) == num;
    }
};
