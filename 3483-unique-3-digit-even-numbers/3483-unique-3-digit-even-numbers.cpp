class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        for (int d : digits) {
            cnt[d]++;
        }
        
        int ans = 0;
        for (int i = 100; i <= 998; i += 2) {
            vector<int> cur(10, 0);
            int temp = i;
            
            cur[temp % 10]++;
            temp /= 10;
            cur[temp % 10]++;
            temp /= 10;
            cur[temp % 10]++;
            
            bool flag = true;
            for (int j = 0; j < 10; j++) {
                if (cur[j] > cnt[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }
        
        return ans;
    }
};