class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> rank(26, 100);
        
        for (int i = 0; i < order.size(); i++) {
            rank[order[i] - 'a'] = i; 
        }

        sort(s.begin(), s.end(), [&](char a, char b) {
            return rank[a - 'a'] < rank[b - 'a'];
        });

        return s;
    }
};