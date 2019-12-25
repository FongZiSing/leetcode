class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        while(n>1) {
            (n&1)&&n!=2147483647?((n&2)>>1&&n!=3?n++:n--):(n>>=1);
            //cout<< n << ' ';
            count++;
        }
        
        return count;
    }
};