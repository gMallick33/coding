class Solution {
public:
    int lcs(int idx1, int idx2, string &word1, string &word2, vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(word1[idx1] == word2[idx2]) return dp[idx1][idx2] = 1 + lcs(idx1 - 1, idx2 - 1, word1, word2, dp);
        else return dp[idx1][idx2] = max(lcs(idx1 - 1, idx2, word1, word2, dp), lcs(idx1, idx2 - 1, word1, word2, dp));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int lcsLen = lcs(n - 1, m - 1, word1, word2, dp);
        return n + m - 2 * lcsLen;
    }
};