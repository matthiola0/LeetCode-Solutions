class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b){
            if (a[1] != b[1]) return stoi(a[1]) < stoi(b[1]);
            return a[0] > b[0];
        });
        vector<int> res(numberOfUsers, 0);
        vector<int> offline(numberOfUsers, 0);
        for (const auto &e : events) {
            if (e[0] == "OFFLINE") {
                int id = stoi(e[2]);
                offline[id] = stoi(e[1]) + 60 - 1;
            } else {    // "MESSAGE"
                int t = stoi(e[1]);
                if (e[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        res[i]++;
                    }
                } else if (e[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offline[i] < t)
                            res[i]++;
                    }
                } else {
                    int id = 0;
                    for (char c : e[2]) {
                        if (c == ' ') {
                            res[id]++;
                            id = 0;
                        } else if (isdigit(c)) {
                            id = id * 10 + c - '0';
                        }
                    }
                    res[id]++;
                }
            }
        }
        return res;
    }
};