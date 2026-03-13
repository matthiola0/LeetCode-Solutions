#define LL long long
typedef tuple<LL, LL, int> tp;

class Solution {
public:
    LL minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        sort(workerTimes.begin(), workerTimes.end());

        priority_queue<tp, vector<tp>, greater<tp>> pq;
        LL ans = 0;

        for (const int& i: workerTimes) {
            pq.push({i, i, 2});
        }

        while (mountainHeight-- > 0) {
            auto [total_time, base_time, next_step] = pq.top();
            pq.pop();

            ans = total_time;
            pq.push({total_time + base_time * next_step, base_time, next_step + 1});
        }

        return ans;
    }
};