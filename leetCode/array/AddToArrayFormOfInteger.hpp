//https://leetcode.com/contest/weekly-contest-123/problems/add-to-array-form-of-integer/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> revA, revK;
        for (auto it = A.rbegin(); it != A.rend(); ++it) {
            revA.push_back(*it);
        }
        while (K) {
            revK.push_back(K % 10);
            K /= 10;
        }
        if (revK.size() == 0) {
            revK.push_back(0);
        }

        int size = revA.size() - revK.size();
        for (int i = 0; i < size; ++i) {
            revK.push_back(0);
        }
        size = revK.size() - revA.size();
        for (int i = 0; i < size; ++i) {
            revA.push_back(0);
        }
        size = revA.size();
        for (int i = 0; i < size; ++i) {
            revA[i] += revK[i];
        }
        for (int i = 0; i < size - 1; ++i) {
            if (revA[i] >= 10) {
                ++revA[i + 1];
                revA[i] -= 10;
            }
        }
        if (revA[size - 1] >= 10) {
            revA.push_back(1);
            revA[size - 1] -= 10;
        }

        revK.clear();
        for (auto it = revA.rbegin(); it != revA.rend(); ++it) {
            revK.push_back(*it);
        }
        return revK;
    }
};
