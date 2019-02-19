class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        for (auto it = emails.begin(); it != emails.end(); ++it) {
            string actual;
            bool print = false, plus = false;
            for (auto itS = it->begin(); itS != it->end(); ++itS) {
                if (print) {
                    actual += *itS;
                } else {
                    switch (*itS) {
                        case '.':
                            break;
                        case '@':
                            print = true;
                            plus = false;
                            actual += '@';
                            break;
                        case '+':
                            plus = true;
                            break;
                        default:
                            if (!plus) {
                                actual += *itS;
                            }
                            break;
                    }
                }
            }
            //cout << actual << endl;
            uniqueEmails.emplace(actual);
        }
        return uniqueEmails.size();
    }
};
