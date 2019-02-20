//https://leetcode.com/problems/fizz-buzz/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> resp;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 != 0 && i % 5 != 0) {
                resp.push_back(to_string(i));
            } else if (i % 3 == 0 && i % 5 == 0) {
                resp.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                resp.push_back("Fizz");
            } else {
                resp.push_back("Buzz");
            }
        }
        return resp;
    }
};
