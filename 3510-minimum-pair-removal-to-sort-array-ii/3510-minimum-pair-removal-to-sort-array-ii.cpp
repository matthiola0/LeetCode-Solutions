using pll = pair<long long, int>;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        vector<long long> vals(nums.begin(), nums.end());
        vector<int> prev(n), next(n);
        vector<bool> valid(n, true);

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }

        int cnt = 0;
        for (int i = 0; i < n-1; i++) {
            if (vals[i] > vals[i + 1]) {
                cnt++;
            }
        }

        if (cnt == 0) return 0;

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        for (int i = 0; i < n-1; i++) {
            pq.push({vals[i] + vals[i+1], i});
        } 

        int ans = 0;
        while (cnt > 0 && !pq.empty()) {
            auto [s, i] = pq.top();
            pq.pop();

            int j = next[i];

            if (!valid[i] || j >= n || !valid[j] || vals[i] + vals[j] != s) continue;

            ans++;
            int p = prev[i];
            int nn = next[j];

            if (p != -1 && vals[p] > vals[i]) cnt--;
            if (vals[i] > vals[j]) cnt--;
            if (nn != n && vals[j] > vals[nn]) cnt--;

            vals[i] += vals[j];
            valid[j] = false;

            next[i] = nn;
            if (nn != n) prev[nn] = i;
            
            if (p != -1) {
                if (vals[p] > vals[i]) cnt++;
                pq.push({vals[p] + vals[i], p});
            }

            if (nn != n) {
                if (vals[i] > vals[nn]) cnt++;
                pq.push({vals[i] + vals[nn], i});
            }
        }

        return ans;
    }
};