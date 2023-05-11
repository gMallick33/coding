class Solution {
public:
    int lcs(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(nums1[idx1] == nums2[idx2]) return dp[idx1][idx2] = 1 + lcs(idx1 - 1, idx2 - 1, nums1, nums2, dp);
        else return dp[idx1][idx2] = max(lcs(idx1 - 1, idx2, nums1, nums2, dp), lcs(idx1, idx2 - 1, nums1, nums2, dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return lcs(n - 1, m - 1, nums1, nums2, dp);
    }
};