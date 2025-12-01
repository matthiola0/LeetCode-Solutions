class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        
        int k = 0, nb = batteries.size();
        while (batteries[nb - 1 - k] > sum / (n - k)) {  // 判斷最大電池是否大於平均
            sum -= batteries[nb - 1 - k];                // 它可以專門負責一台電腦，把它踢掉
            k++;
        }

        return sum / (n-k);         // 平均分給剩餘電腦
    }
};