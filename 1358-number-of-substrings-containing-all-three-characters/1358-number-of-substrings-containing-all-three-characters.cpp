class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last_seen = {-1, -1, -1};
        int total_substrings = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            last_seen[s[i] - 'a'] = i;
            
            int min_index = min({last_seen[0], last_seen[1], last_seen[2]});
            
            if (min_index != -1) 
                total_substrings += (min_index + 1);
        }
        
        return total_substrings;
    }
};