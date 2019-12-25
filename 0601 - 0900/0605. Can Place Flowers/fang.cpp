// 一个解决问题的新思路
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int remnant = 0;
        int avoid [] = { 1, 0, 0, 1 };

        flowerbed.insert(flowerbed.begin(), avoid, avoid + 2);
        flowerbed.insert(flowerbed.end(), avoid + 2, avoid + 4);
        for(int p=0, q=2; q < flowerbed.size(); ++q)
            if(flowerbed[q]) {
                remnant += (q-p-2)/2;
                p = q;
            }

        return n <= remnant;
    }
};