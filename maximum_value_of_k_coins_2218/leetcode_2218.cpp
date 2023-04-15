class Solution {
public:
    int func(int idx, vector<vector<int>> &piles, int k, vector<vector<int>> &dp){
        if(k <= 0 || idx == piles.size()) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        int res = INT_MIN;
        int curr = 0;
        for(int j = 0; j < piles[idx].size() && j < k; j++){
            curr += piles[idx][j];
            res = max(res, curr + func(idx + 1, piles, k - j - 1, dp));
        }
        res = max(res, func(idx + 1, piles, k, dp));
        return dp[idx][k] = res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return func(0, piles, k, dp);
    }
};