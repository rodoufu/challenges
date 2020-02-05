// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<tuple<int, int>> cont;
        
        for (int i = 0; i < mat.size(); ++i) {
            cont.push_back(make_tuple(i, accumulate(mat[i].begin(), mat[i].end(), 0)));
        }
        sort(cont.begin(), cont.end(), [](auto a, auto b) {
            if (get<1>(a) == get<1>(b)) {
                return get<0>(a) < get<0>(b);
            }
            return get<1>(a) < get<1>(b); 
        });
        
        /*for (auto l : cont) {
            printf("%d-%d\n", get<0>(l), get<1>(l));
        }*/
        
        vector<int> resp;
        for (int i = 0; i < k && i < cont.size(); ++i) {
            resp.push_back(get<0>(cont[i]));
        }
        return resp;
    }
};
