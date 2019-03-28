// https://leetcode.com/problems/goat-latin/
class Solution {
public:
    string toGoatLatin(string S) {
        string resp;
        unordered_set<char> vowels = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        };

        int cont = 1;
        int size = S.length();
        int inicio = 0, fim;

        while (inicio < size) {
            while (inicio < size && !isalnum(S[inicio])) {
                //resp.push_back(S[inicio++]);
                ++inicio;
            }
            
            fim = inicio + 1;
            while (fim < size && isalnum(S[fim])) {
                ++fim;
            }
            
            //printf("i:%d,f:%d,s:%d\n", inicio, fim, size);
            if (inicio < size) {
                if (vowels.find(S[inicio]) != vowels.end()) {
                    for (int i = inicio; i < fim; ++i) {
                        resp.push_back(S[i]);
                    }
                } else {
                    for (int i = inicio + 1; i < fim; ++i) {
                        resp.push_back(S[i]);
                    }
                    resp.push_back(S[inicio]);
                }
                
                resp.push_back('m');
                resp.push_back('a');
                for (int i = 0; i < cont; ++i) {
                    resp.push_back('a');
                }
                ++cont;

                if (fim < size) {
                    resp.push_back(S[fim]);
                }
            }
            inicio = fim + 1;
        }
        
        while (resp.size() && !isalnum(resp[resp.size() - 1])) {
            resp.pop_back();
        }

        return resp;
    }
};
