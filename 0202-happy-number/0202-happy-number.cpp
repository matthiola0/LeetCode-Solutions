class Solution {
private:
    int nextNumber(int n) {
        int res = 0;
        while (n > 0) {
            int digit = n % 10;
            res += digit * digit;
            n /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> visited;

        while(!visited.count(n)) {
            visited.insert(n);
            n = nextNumber(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
};