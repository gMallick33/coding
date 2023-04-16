class Solution {
public:
    int func(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini= 1e9;
        for(int ind = i; ind <= j; ind++){
            int cost = cuts[j + 1] - cuts[i - 1] + func(i, ind - 1, cuts, dp) + func(ind + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());
        int k = cuts.size();
        vector<vector<int>> dp(k - 1, vector<int> (k - 1, -1));
        return func(1, k - 2, cuts, dp);
    }
};