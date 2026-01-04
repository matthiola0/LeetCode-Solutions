class Solution {
private:
    int count(int n) {
        int sum = 0;
        int divCount = 0;
        
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                sum += i;
                divCount++;
                
                if (i * i != n) {
                    sum += n / i;
                    divCount++;
                }
            }
            if (divCount > 4) return -1;
        }
        return (divCount == 4) ? sum : -1;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int n: nums) {
            int val = count(n);
            if (val != -1) res += val;
        }
        return res;
    }
};