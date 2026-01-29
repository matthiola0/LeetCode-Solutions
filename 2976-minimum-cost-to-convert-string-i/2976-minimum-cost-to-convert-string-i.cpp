class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX/4));
        for (int i = 0; i < original.size(); i++) {
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            dist[a][b] = min(dist[a][b], cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (i == j) dist[i][j] = 0;
                    else if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < source.size(); i++) {
            int v = dist[source[i] - 'a'][target[i] - 'a'];
            if (v == INT_MAX/4) return -1;
            res += v;
        }

        return res;
    }
};