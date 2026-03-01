class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char c: n) {
            int tmp = c - '0';
            if (tmp > ans) ans = tmp;
        }
        return ans;
    }
};