// bad code, bullshit, but work and AC.
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        bool res1, res2, res3;
        int diff = abs(x - y);
        if (x + y < z)
            return false;
        if (z == 0)
            return true;
        res1 = x && (x <= z ? canMeasureWater(x, y, z - x) : false);
        res2 = y && (y <= z ? canMeasureWater(x, y, z - y) : false);
        res3 = x && y && diff && (diff <= z ? canMeasureWater(x, y, z - diff) : canMeasureWater(x >= y ? diff : x, y > x ? diff : y, z));

        return res1 || res2 || res3;
    }
};