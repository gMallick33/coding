class Solution {
public:
    int lcs(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s[idx1] == t[idx2]) return dp[idx1][idx2] = 1 + lcs(idx1 - 1, idx2 - 1, s, t, dp);
        else return dp[idx1][idx2] = max(lcs(idx1 - 1, idx2, s, t, dp), lcs(idx1, idx2 - 1, s, t, dp));
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int lcs_len = lcs(n - 1, n - 1, s, t, dp);
        return n - lcs_len;
    }
};