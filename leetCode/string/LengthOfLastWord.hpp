class Solution {
public:
    int lengthOfLastWord(string s) {
        char * s_cstr = (char *) s.c_str();
        char * it = strtok(s_cstr, " ");
        int len = 0;
        while (it) {
            len = strlen(it);
            it = strtok(NULL, " ");
        }
        return len;
    }
};
