class Solution {
    long long MOD = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> prefSum(n + 1, 0);
        vector<int> prefCnt(n + 1, 0);
        vector<long long> prefVal(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            prefSum[i + 1] = prefSum[i] + digit;

            if (digit != 0) {
                prefCnt[i + 1] = prefCnt[i] + 1;
                prefVal[i + 1] = (prefVal[i] * 10 + digit) % MOD;
            } else {
                prefCnt[i + 1] = prefCnt[i];
                prefVal[i + 1] = prefVal[i];
            }
        }

        vector<long long> powers(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            powers[i] = (powers[i - 1] * 10) % MOD;
        }
        
        vector<int> res;
        for (const auto q : queries) {
            int l = q[0], r = q[1];
            long long sum = prefSum[r + 1] - prefSum[l];
            if (sum == 0) {
                res.push_back(0);
                continue;
            }
            int len = prefCnt[r + 1] - prefCnt[l];
            long long left = (prefVal[l] * powers[len]) % MOD;
            long long x = (prefVal[r + 1] - left + MOD) % MOD;

            long long result = (x * (sum % MOD)) % MOD;
            res.push_back((int)result);
        }
        return res;
    }
};