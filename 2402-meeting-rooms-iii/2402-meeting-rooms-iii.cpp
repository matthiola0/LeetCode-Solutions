typedef long long LL;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> room(n);
        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
        priority_queue<int, vector<int>, greater<int>> empty_room;
        for (int i = 0; i < n; i++) empty_room.push(i);

        sort(meetings.begin(), meetings.end());
        for(int i = 0; i < meetings.size(); i++) {
            int start_time = meetings[i][0];
            while (!pq.empty() && pq.top().first <= start_time) {
                empty_room.push(pq.top().second);
                pq.pop();
            }
            if (pq.size() < n) {
                int room_id = empty_room.top();
                empty_room.pop();
                pq.push({meetings[i][1], room_id});
                room[room_id]++;
            } else {
                auto [end_time, room_id] = pq.top();
                pq.pop();
                end_time += meetings[i][1] - meetings[i][0];
                pq.push({end_time, room_id});
                room[room_id]++;
            }
        }

        int res = 0, max_meet = 0;
        for (int i = 0; i < n; i++) {
            if (max_meet < room[i]) {
                max_meet = room[i];
                res = i;
            }
        }
        return res;
    }
};