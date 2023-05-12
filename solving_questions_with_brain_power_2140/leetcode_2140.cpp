class Solution {
public:
    long long func(int idx, vector<vector<int>> &questions, vector<long long> &dp){
        if(idx >= questions.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long solve = 0, notSolve = 0;
        solve = questions[idx][0] + func(idx + questions[idx][1] + 1, questions, dp);
        notSolve = func(idx + 1, questions, dp);
        return dp[idx] = max(solve, notSolve);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return func(0, questions, dp);
    }
};