//https://leetcode.com/problems/first-bad-version/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

inline bool isBadVersionCache(map<long long, bool> &cache, long long version) {
    auto value = cache.find(version);
    if (value != cache.end()) {
        return value->second;
    }
    return cache[version] = isBadVersion(version);
}

class Solution {
public:
    int firstBadVersion(int n) {
        map<long long, bool> cache;
        long long inf = 0;
        long long sup = n;
        long long meio;
        while (inf <= sup) {
            meio = (inf + sup) / 2;
            if (isBadVersionCache(cache, meio) && !isBadVersionCache(cache, meio - 1)) {
                return (int) meio;
            }
            if (isBadVersionCache(cache, meio)) {
                sup = meio - 1;
            } else {
                inf = meio + 1;
            }
        }
        return n;
    }
};
