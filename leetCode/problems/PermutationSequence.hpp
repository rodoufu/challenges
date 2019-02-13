class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> resp;
        for (int i = 1; i <= n; ++i) {
            resp.push_back(i);
        }
        for (int i = 0; i < k - 1; ++i) {
            next_permutation(resp.begin(), resp.end());
        }
        
        stringstream ss;
        copy(resp.begin(), resp.end(), ostream_iterator<int>(ss, ""));
        return ss.str();
    }
};
