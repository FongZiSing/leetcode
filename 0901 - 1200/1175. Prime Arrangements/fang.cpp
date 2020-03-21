class Solution {
    static const int mod = int(1e9 + 7);
    long factorial(int num) {
        if (num == 0)
            return 1;
        long result = num;
        while (--num) {
            result *= num;
            result %= mod;
        }
        return result;
    }

public:
    int numPrimeArrangements(int n) {
        static const int prime[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        const int primeNum = upper_bound(prime, prime + 25, n) - prime;
        return (factorial(primeNum) * factorial(n - primeNum)) % mod;
    }
};