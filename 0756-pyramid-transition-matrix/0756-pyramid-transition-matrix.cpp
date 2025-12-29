class Solution {
private:
    map<string,bool> dp;
    bool solve(unordered_map<string, vector<char>> &mp, int ind, string newlayer, string oldlayer, int n) {
        if (n == 1) return true;
        
        if (ind == n - 1) {
            if (dp.count(newlayer)) return dp[newlayer];
            return dp[newlayer] = solve(mp, 0, "", newlayer, n - 1);
        }

        string tmp = oldlayer.substr(ind, 2);

        if(!mp.count(tmp)) return false; 

        for(auto x : mp[tmp]){
            if(solve(mp, ind + 1, newlayer + x, oldlayer, n)) 
                return true;
        }
        return false; 
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        unordered_map<string, vector<char>> mp;

        for(auto x : allowed){
            mp[x.substr(0,2)].push_back(x[2]);
        }

        return solve(mp, 0, "", bottom, n);
    }
};