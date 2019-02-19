class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> n1, n2;
        for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
            n1.push_back(*it - '0');
        }
        for (auto it = num2.rbegin(); it != num2.rend(); ++it) {
            n2.push_back(*it - '0');
        }
        if (n1.size() < n2.size()) {
            swap(n1, n2);
        }
        
        vector<int> resp;
        int size1 = n1.size(), size2 = n2.size();
        resp.insert(resp.end(), size1 + size2, 0);
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                resp[j + i] += n1[i] * n2[j];
            }
        }
        
        // Plus one
        for (int i = 0; i < resp.size(); ++i) {
            while (resp[i] > 9) {
                if (i < resp.size() - 1) {
                    resp[i + 1] += resp[i] / 10;
                } else {
                    resp.push_back(resp[i] / 10);
                }
                resp[i] %= 10;
            }
        }
        // Removing trailing zeros
        while (resp.size() > 1 && !resp[resp.size() - 1]) {
            resp.pop_back();
        }
        string respStr;
        for (auto it = resp.rbegin(); it != resp.rend(); ++it) {
            respStr += '0' + *it;
        }
        return respStr;
    }
};
