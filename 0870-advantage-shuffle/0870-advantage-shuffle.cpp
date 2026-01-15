class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<pair<int, int>> nums3(n);
        for (int i = 0; i < n; i++) {
            nums3[i] = {nums2[i], i};
        }

        sort(nums1.begin(), nums1.end());
        sort(nums3.begin(), nums3.end());

        vector<int> res(n, -1);
        vector<int> remaining;
        int j = 0;
        for (int i = 0; i < n; i++) {
            int idx = nums3[j].second;
            if (nums1[i] > nums3[j].first) {
                res[idx] = nums1[i];
                j++;
            } else {
                remaining.push_back(nums1[i]);
            }
        }

        j = 0;
        for (int i = 0; i < n; i++) {
            if (res[i] == -1) {
                res[i] = remaining[j++];
            }
        }

        return res;
    }
};