class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int cur_max = 0;
        int ans = 0;
        for (const auto& event : events) {
            int start = event[0], end = event[1];
            int val = event[2];

            while (!pq.empty() && pq.top().first < start) {
                cur_max = max(cur_max, pq.top().second);
                pq.pop();
            }
            ans = max(ans, cur_max + val);
            pq.push({end, val});
        } 
        return ans;
    }
};