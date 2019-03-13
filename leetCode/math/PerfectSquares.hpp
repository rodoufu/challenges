// https://leetcode.com/problems/perfect-squares/
class Solution {
private:
    inline vector<int> squares(int n) {
        vector<int> resp;
        for (int i = 1; i * i <= n; ++i) {
            resp.push_back(i * i);
        }
        return vector<int>(resp.rbegin(), resp.rend());
    }
    
    int countSums(vector<int>& squares, int actual, int target, int count, int better) {
        //printf("%d,%d\n", actual, target);
        if (actual == target) {
            return count;
        }
        if (better == 1 || actual > target || count >= better) {
            return better;
        }
        
        for (auto &x : squares) {
            if (better == 1) {
                break;
            }
            better = min(better, countSums(squares, actual + x, target, count + 1, better));
        }

        return better;
    }
public:
    int numSquares(int n) {
        vector<int> sq = squares(n);
        /*for (auto x : sq) {
            printf("%d ", x);
        }
        puts("");*/
        return countSums(sq, 0, n, 0, n);
    }
};
