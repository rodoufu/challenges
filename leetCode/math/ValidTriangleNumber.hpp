//https://leetcode.com/problems/valid-triangle-number/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cont = 0;
        int size = nums.size();
        
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            for (auto jt = it + 1; jt != nums.end(); ++jt) {
                for (auto kt = jt + 1; kt != nums.end(); ++kt) {
                    cont += *it + *jt > *kt
                        && *jt + *kt > *it 
                        && *it + *kt > *jt
                        ? 1 : 0;
                }
            }
        }
        
        return cont;
    }
};
