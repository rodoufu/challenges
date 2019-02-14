class Solution {
public:
    string addBinary(string a, string b) {
        vector<short> numA, numB;
        int sizeA = a.length(), sizeB = b.length();
        for (int i = sizeA - 1; i >= 0; --i) {
            numA.push_back(a[i] - '0');
        }
        for (int i = sizeB - 1; i >= 0; --i) {
            numB.push_back(b[i] - '0');
        }
        
        if (sizeA > sizeB) {
            for (int i = 0; i < sizeB; ++i) {
                numA[i] += numB[i];
            }
            for (int i = 0; i < sizeA - 1; ++i) {
                if (numA[i] > 1) {
                    numA[i] -= 2;
                    ++numA[i + 1];
                }
            }
            if (numA[sizeA - 1] > 1) {
                numA[sizeA - 1] -= 2;
                numA.push_back(1);
            }
            sizeA = numA.size();
            string resp;
            for (int i = sizeA - 1; i >= 0; --i) {
                resp += '0' + numA[i];
            }
            return resp;
        } else {
            for (int i = 0; i < sizeA; ++i) {
                numB[i] += numA[i];
            }
            for (int i = 0; i < sizeB - 1; ++i) {
                if (numB[i] > 1) {
                    numB[i] -= 2;
                    ++numB[i + 1];
                }
            }
            if (numB[sizeB - 1] > 1) {
                numB[sizeB - 1] -= 2;
                numB.push_back(1);
            }
            sizeB = numB.size();
            string resp;
            for (int i = sizeB - 1; i >= 0; --i) {
                resp += '0' + numB[i];
            }
            return resp;
        }
    }
};
