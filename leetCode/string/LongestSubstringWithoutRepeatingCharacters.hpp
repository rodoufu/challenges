//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        unordered_set<char> letras;
        int m = 0;
        for (int i = 0; i<size;++i){
            letras.clear();
            letras.emplace(s[i]);
            m = max(m, 1);
            
            for (int j = 1+i; j<size;++j){
              if (letras.find(s[j])==letras.end()){
                  m = max(m,j-i +1);
                  //printf("%d,%d\n", i, j);
                  
                  } else {
                  break;
                  }
                letras.emplace(s[j]);
                }
            }
        return m;
    }
};
