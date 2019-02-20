//https://leetcode.com/contest/weekly-contest-123/problems/satisfiability-of-equality-equations/
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        map<char, unordered_set<char>> igual, diferente;
        for (auto it = equations.begin(); it != equations.end(); ++it) {
            auto text = *it;
            if (igual.find(text[0]) == igual.end()) {
                igual.emplace(text[0], unordered_set<char>());
            }
            if (igual.find(text[3]) == igual.end()) {
                igual.emplace(text[3], unordered_set<char>());
            }

            if (diferente.find(text[0]) == diferente.end()) {
                diferente.emplace(text[0], unordered_set<char>());
            }
            if (diferente.find(text[3]) == diferente.end()) {
                diferente.emplace(text[3], unordered_set<char>());
            }
            
            if (text[1] == '=') {
                //printf("%c-%c -> igual\n", text[0], text[3]);
                //printf("%c-%c -> igual\n", text[3], text[0]);
                igual[text[0]].insert(text[3]);
                igual[text[3]].insert(text[0]);
            } else {
                //printf("%c-%c -> diferente\n", text[0], text[3]);
                //printf("%c-%c -> diferente\n", text[3], text[0]);
                diferente[text[0]].insert(text[3]);
                diferente[text[3]].insert(text[0]);
            }
        }
        
        bool keepGoing = true;
        while (keepGoing) {
            keepGoing = false;
            for (auto it = igual.begin(); it != igual.end(); ++it) {
                for (auto itInner = it->second.begin(); itInner != it->second.end(); ++itInner) {
                    auto innerValue = igual[*itInner];
                    int size = it->second.size();
                    it->second.insert(innerValue.begin(), innerValue.end());
                    if (it->second.size() != size) {
                        keepGoing = true;
                    }
                }
            }    
        }
        
        /*
        keepGoing = true;
        while (keepGoing) {
            keepGoing = false;
            for (auto it = diferente.begin(); it != diferente.end(); ++it) {
                for (auto itInner = it->second.begin(); itInner != it->second.end(); ++itInner) {
                    auto innerValue = diferente[*itInner];
                    int size = it->second.size();
                    it->second.insert(innerValue.begin(), innerValue.end());
                    if (it->second.size() != size) {
                        keepGoing = true;
                    }
                }
            }    
        }
        */

        for (auto it = diferente.begin(); it != diferente.end(); ++it) {
            if (it->second.find(it->first) != it->second.end()) {
                return false;
            }
        }


        for (auto it = igual.begin(); it != igual.end(); ++it) {
            auto diferenteSet = diferente[it->first];
            for (auto itIgual = it->second.begin(); itIgual != it->second.end(); ++itIgual) {
                if (diferenteSet.find(*itIgual) != diferenteSet.end()) {
                    //printf("%c-%c -> false\n", it->first, *itIgual);
                    return false;
                }
            }
        }
        
        return true;
    }
};
