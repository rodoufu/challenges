// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
class Solution {
private:
    inline int dist(char a, char b) {
        int d = a - 'a';
        d -= b -'a';
        d = (d+26)%26;
        return d;
    }
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char rp ='a';
        int d = 30;
        for (auto &x : letters){
            int s1 = dist(x, target);
            if (s1<d && s1){
                d=s1;
                rp=x;
            }
        }
        return rp;
    }
};
