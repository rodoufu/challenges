// https://leetcode.com/problems/number-of-recent-calls/
class RecentCounter {
private:
    set<int> calls;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        calls.emplace(t);
        auto it = calls.lower_bound(t - 3000);
        int count = 0;
        while (it != calls.end()) {
            ++count;
            ++it;
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
