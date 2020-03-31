// https://leetcode.com/problems/string-compression/
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() < 2)
            return chars.size();
        auto it = chars.begin();
        char last = '\0';
        auto pos = it;
        int count = 1;
        while (it != chars.end()) {
            //printf("it: %c, l:%c, %d - c: %d --- ", *it, last, it - chars.begin(), count);
            if (*it == last) {
                ++count;
            } else {
                if (count > 1) {
                    //printf("\ncount: %d\n", count);
                    auto temp = it - 1;
                    while (count) {
                        *temp = '0' + count % 10;
                        count /= 10;
                        --temp;
                    }
                    while (temp != pos) {
                        chars.erase(temp--);
                        --it;
                    }
                }
                count = 1;
                last = *it;
                pos = it;
            }
            ++it;
            //printf("it: %c, l:%c, %d - c: %d\n", *it, last, it - chars.begin(), count);
        }
        if (count > 1) {
            //printf("2count: %d\n", count);
            auto temp = chars.end() - 1;
            while (count) {
                *temp = '0' + count % 10;
                count /= 10;
                --temp;
            }
            last = *temp;
            while (temp != pos) {
                chars.erase(temp--);
                --it;
            }
        }

        return chars.size();
    }
};
