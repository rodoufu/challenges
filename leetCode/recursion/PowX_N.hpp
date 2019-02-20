//https://leetcode.com/explore/learn/card/recursion-i/256/complexity-analysis/2380/
class Solution {
public:
    double myPow(double x, int n) {
        if (fabs(fabs(x) - 1.0) < 1e-10) {
            return n % 2 == 0 ? x * x : x;
        }
        map<long long int, double> idxValue = {
            {0, 1},
            {1, x},
            {2, x * x}
        };
        const bool negativeExpo = n < 0;
        double value = 1;
        const long long int cn = negativeExpo ? -((long long int)n) : n;
        long long int vn = cn;
        long long int itValue = 2;
        while (vn) {
            if (value < 1e-10) {
                break;
            }
            /*
            printf("idxValue\n");
            for (auto& it : idxValue) {
                cout << it.first << "," << it.second << endl;
            }
            */
            auto it = idxValue.lower_bound(itValue);
            if (it == idxValue.end()) {
                //cout << "parou" << endl;
                break;
            }
            while (it->first > vn) {
                --it;
            }
            //cout << "itF:" << it->first << ",n:" << vn << ",v:" << value << endl;
            value *= it->second;
            itValue = it->first + cn - vn;
            idxValue[itValue] = value;
            vn -= it->first;
        }
        //value = value < 0 ? -value : value;
        //value = x < 0 && cn % 2 == 1 ? -value : value;
        return negativeExpo ? 1 / value : value;
    }
};
