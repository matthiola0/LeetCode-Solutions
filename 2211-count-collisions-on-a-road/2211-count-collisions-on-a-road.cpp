class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        for (int i = 1; i < directions.size(); i++) {
            if (directions[i] == 'L') {
                if (directions[i - 1] == 'R') {
                    res += 2;
                    directions[i] = 'S';
                }
                if (directions[i - 1] == 'S') {
                    res ++;
                    directions[i] = 'S';
                }
            }
            else if (directions[i] == 'S' && directions[i - 1] == 'R') {
                res ++;
            }
        }
        return res;
    }
};