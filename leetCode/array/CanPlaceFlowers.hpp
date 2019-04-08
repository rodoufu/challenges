// https://leetcode.com/problems/can-place-flowers/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        auto size = flowerbed.size();
        if (size == 1 && !flowerbed[0]) {
            flowerbed[0] = 1;
            --n;
        }
        if (size > 1 && !flowerbed[0] && !flowerbed[1]) {
            flowerbed[0] = 1;
            --n;
        }
        for (int i = 1; i < size - 1 && n > 0; ) {
            if (!flowerbed[i - 1]
               && !flowerbed[i] && !flowerbed[i + 1]) {
                flowerbed[i] = 1;
                i += 2;
                --n;
            } else {
                ++i;
            }
        }
        if (size > 1 && !flowerbed[size - 2] && !flowerbed[size - 1]) {
            flowerbed[size - 1] = 1;
            --n;
        }
        return n <= 0;
    }
};
