class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> added;
        int cont = 0;
        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); ) {
            if (added.find(*it) != added.end()) {
                nums.erase(it);
            } else {
                added.insert(*it);
                ++it;
            }
        }
        return nums.size();
    }
};
