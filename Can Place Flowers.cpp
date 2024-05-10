#include <vector>
class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();

        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0) {
                int prev = (i == 0) ? 0 : flowerbed[i - 1];
                int next = (i == size - 1) ? 0 : flowerbed[i + 1];
                if (prev == 0 && next == 0) {
                    flowerbed[i] = 1;
                    ++count;
                }
            }
        }
        return count >= n;
    }
};