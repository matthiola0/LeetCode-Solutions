class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int, greater<int>> sums;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                sums.insert(grid[r][c]);
                
                int L = 1;
                while (r - L >= 0 && r + L < m && c - L >= 0 && c + L < n) {
                    int current_sum = 0;
                    
                    int curr_r = r - L;
                    int curr_c = c;
                    
                    for (int i = 0; i < L; ++i) {
                        current_sum += grid[curr_r][curr_c];
                        curr_r++;
                        curr_c++;
                    }
                        
                    for (int i = 0; i < L; ++i) {
                        current_sum += grid[curr_r][curr_c];
                        curr_r++;
                        curr_c--;
                    }
                        
                    for (int i = 0; i < L; ++i) {
                        current_sum += grid[curr_r][curr_c];
                        curr_r--;
                        curr_c--;
                    }
                        
                    for (int i = 0; i < L; ++i) {
                        current_sum += grid[curr_r][curr_c];
                        curr_r--;
                        curr_c++;
                    }
                        
                    sums.insert(current_sum);
                    
                    L++;
                }
            }
        }

        vector<int> result;
        int count = 0;
        for (int sum : sums) {
            result.push_back(sum);
            count++;
            if (count == 3) {
                break;
            }
        }

        return result;
    }
};