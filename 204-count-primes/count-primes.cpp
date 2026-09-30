class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int size = n / 2;
        vector<char> isPrime(size, true);

        int limit = sqrt(n);
        for (int i = 3; i <= limit; i += 2) {
            if (isPrime[i/2]) {
                for (int j = i*i; j < n; j += 2*i) {
                    isPrime[j/2] = false;
                }
            }
        }

        int count = 1; 
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i/2]) count++;
        }
        return count;
    }
};
