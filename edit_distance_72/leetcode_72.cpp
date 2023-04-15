class Solution {
public:
    int func(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i < 0){
            return j + 1;
        }
        else if(j < 0){
            return i + 1;
        }
        else{
            if(dp[i][j] != -1){
                return dp[i][j];
            }
            if(word1[i] == word2[j]){
                dp[i][j] = func(i - 1, j - 1, word1, word2, dp);
                return dp[i][j];
            }
            dp[i][j] = min(1 + func(i, j - 1, word1, word2, dp), min(1 + func(i - 1, j, word1, word2, dp), 1 + func(i - 1, j - 1, word1, word2, dp)));
            return dp[i][j];
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n - 1, m - 1, word1, word2, dp);
    }
};