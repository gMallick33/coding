class Solution {
public:
    int mod = 1e9 + 7;
    int func(int idx, vector<int> &group, vector<int> &profit, int minProfit, int n, vector<vector<vector<int>>> &dp){
        if(idx == group.size()){
            if(minProfit <= 0) return 1;
            else return 0;
        }
        if(minProfit < 0) minProfit = 0;
        if(dp[idx][minProfit][n] != -1) return dp[idx][minProfit][n];
        long long take = 0;
        long long not_take = 0;
        if(group[idx] <= n){
            take = func(idx + 1, group, profit, minProfit - profit[idx], n - group[idx], dp);
            take = take % mod;
        }
        not_take = func(idx + 1, group, profit, minProfit, n, dp);
        not_take = not_take % mod;
        return dp[idx][minProfit][n] = (take + not_take) % mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int g = group.size();
        vector<vector<vector<int>>> dp(g, vector<vector<int>> (minProfit + 1, vector<int>(n + 1, -1)));
        return func(0, group, profit, minProfit, n, dp);
    }
};