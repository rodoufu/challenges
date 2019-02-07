class Solution {
private:
    map<int, int> cache;
public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 1;
        }
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }
        return cache[n] = climbStairs(n - 1) + (n > 1 ? climbStairs(n - 2) : 0);
    }
};
