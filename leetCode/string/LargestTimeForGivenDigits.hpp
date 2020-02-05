// https://leetcode.com/problems/largest-time-for-given-digits
class Solution {
private:
    int getMin(vector<int> &a) {
        return a[3] + 10*a[2]+60*a[1]+600*a[0];
    }
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> resp({-1,0,0,0}), t({0,0,0,0});
        int v =-10;
        
        for (int i=0; i<4;++i){
            if (A[i] > 2) continue;
            for (int j=0; j<4;++j){
                if (i==j) continue;
                if (A[i]==2 && A[j]>3) continue;
                for(int k=0; k<4; ++k){
                    if (A[k] > 5) continue;
                    if (i==k || j==k) continue;
                    for (int l=0; l<4; ++l){
                        if (i==l || j==l || k==l) continue;
                        //printf("%d%d%d%d", i, j, k, l);
                        t[0] =A[i];
                        t[1] =A[j];
                        t[2]=A[k];
                        t[3]=A[l];
                        int tv = getMin(t);
                        if (tv>v){
                            v=tv;
                            resp =t;
                            //printf(" %d", v);
                        }
                        //puts("");
                    }
                }
            }
        }
        
        if (resp[0] ==-1) return "";
        return ""s +to_string(resp[0]) +to_string(resp[1]) + ":"s +to_string(resp[2]) + to_string(resp[3]);
    }
};
