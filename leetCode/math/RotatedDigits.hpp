// https://leetcode.com/problems/rotated-digits/
class Solution {
private:
    int rotate(int n) {
        int resp = 0, multi = 1;
        while (n) {
            int x = n % 10;
            switch (x) {
                case 1:
                case 8:
                case 0:
                    resp += multi * x;
                    break;
                case 2:
                    resp += multi * 5;
                    break;
                case 5:
                    resp += multi * 2;
                    break;
                case 6:
                    resp += multi * 9;
                    break;
                case 9:
                    resp += multi * 6;
                    break;
                default:
                    return -1;
            }

            multi *= 10;
            n /= 10;
        }
        return resp;
    }
public:
    int rotatedDigits(int N) {
        int rotated;
        int cont = 0;
        
        for (int i = 1; i <= N; ++i) {
            rotated = rotate(i);
            cont += (rotated != -1 && rotated != i) ? 1 : 0;
            //printf("%d, %d, %d\n", i, rotated, cont);
        }
        return cont;
    }
};
