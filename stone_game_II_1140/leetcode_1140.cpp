class Solution {
public:

    int func(int idx, int M, vector<int> &piles, vector<int> &suffix, vector<vector<int>> &dp){
        if(idx == piles.size()) return 0;
        if(idx + 2 * M >= piles.size()) return suffix[idx];
        if(dp[idx][M] != -1) return dp[idx][M];
        int result = 0;
        for(int x = 1; x <= 2 * M; x++){
            result = max(result, suffix[idx] - func(idx + x, max(x, M), piles, suffix, dp));
        }
        return dp[idx][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        if(piles.size() == 0) return 0;
        int n = piles.size();
        vector<int> suffix(n);
        suffix[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(0, 1, piles, suffix, dp);
    }
};