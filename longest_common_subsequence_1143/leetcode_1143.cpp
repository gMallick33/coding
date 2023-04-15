class Solution {
public:
    int func(int n, int m, string &text1, string &text2, vector<vector<int>> &dp){
        if((n < 0) || (m < 0)){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        else{
            if(text1[n] == text2[m]){
                dp[n][m] = 1 + func(n - 1, m - 1, text1, text2, dp);
            }
            else{
                dp[n][m] = max(func(n - 1, m, text1, text2, dp), func(n, m - 1, text1, text2, dp));
            }
        }
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n - 1, m - 1, text1, text2, dp);
    }
};