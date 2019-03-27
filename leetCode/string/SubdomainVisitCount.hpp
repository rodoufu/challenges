// https://leetcode.com/problems/subdomain-visit-count/
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> values;
        for (auto &x : cpdomains) {
            int visits, spacePos = -1;
            sscanf(x.c_str(), "%d", &visits);
            int len = x.length();
            while (spacePos < len && x[++spacePos] != ' ') { }
            x = x.substr(spacePos + 1);
            if (values.find(x) == values.end()) {
                values[x] = 0;
            }
            values[x] += visits;
            //printf("%s\n", x.c_str());
            
            while (true) {
                spacePos = 0;
                len = x.length();
                while (spacePos < len && x[++spacePos] != '.') { }
                if (spacePos == len) {
                    break;
                }
                //printf("%d/%d\n", spacePos, len);
                x = x.substr(spacePos + 1);
                //printf("%s\n", x.c_str());
                if (values.find(x) == values.end()) {
                    values[x] = 0;
                }
                values[x] += visits;
            }
        }
        
        vector<string> resp;
        for (auto &x : values) {
            //printf("%s: %d\n", x.first.c_str(), x.second);
            resp.push_back(to_string(x.second) + " " + x.first);
        }

        return resp;
    }
};
