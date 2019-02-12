class Solution {
public:
    int romanToInt(string s) {
        map<char, int> values = { {'I', 1}, {'V', 5},
            {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500},
            {'M', 1000}
        };
        int value = 0;
        int last, actual = INT_MAX;
        const char * num = s.c_str();
        int size = s.length();
        for (int i = 0; i < size; ++i) {
            last = actual;
            actual = values[num[i]];
            value += last >= actual ? actual : - 2 * last + actual;
        }
        return value;
    }
};
