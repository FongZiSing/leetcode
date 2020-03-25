// My solution.
class Solution {
public:
    int bitwiseComplement(int N) {
        int count = 0;
        int res = !N;
        while (N) {
            res = (!(N & 1) << count) + res;
            N >>= 1;
            count++;
        }
        return res;
    }
};

// A simpler solution, but is it really efficient?
class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        int binaryLen = int(log2(N)) + 1;
        int mask = (1 << binaryLen) - 1; //连续binaryLength个1
        return N ^ mask;                 //与若干1异或 = 按位取反
    }
};