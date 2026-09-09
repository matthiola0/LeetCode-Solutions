class Solution {
public:
    long long countCommas(long long n) {
        if(n <= 999) return 0;

        long long res = 0;
        long long start = 1000;

        while(start <= n){
            res += n - start + 1;
            start *= 1000;
        }

        return res;
    }
};