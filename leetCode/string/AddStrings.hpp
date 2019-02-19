class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> n1, n2;
        for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
            n1.push_back(*it - '0');
        }
        for (auto it = num2.rbegin(); it != num2.rend(); ++it) {
            n2.push_back(*it - '0');
        }
        n1.insert(n1.end(), max(0, int(n2.size() - n1.size())), 0);
        n2.insert(n2.end(), max(0, int(n1.size() - n2.size())), 0);
        int size = n1.size();
        for (int i = 0; i < size; ++i) {
            n1[i] += n2[i];
        }
        for (int i = 0; i < size - 1; ++i) {
            if (n1[i] > 9) {
                n1[i + 1] += 1;
                n1[i] -= 10;
            }
        }
        if (n1[size - 1] > 9) {
            n1[size - 1] -= 10;
            n1.push_back(1);
        }
        string resp;
        for (auto it = n1.rbegin(); it != n1.rend(); ++it) {
            resp += '0' + *it;
        }
        return resp;
    }
};
