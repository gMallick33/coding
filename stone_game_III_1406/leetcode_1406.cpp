class Solution {
public:

    int func(int idx, vector<int> &stoneValue, vector<int> &dp){
        int n = stoneValue.size();
        if(idx >= stoneValue.size()) return  0;
        if(dp[idx] != -1) return dp[idx];
        int takeOne = stoneValue[idx] - func(idx + 1, stoneValue, dp);
        int takeTwo = INT_MIN;
        if(idx + 1 < n) takeTwo = stoneValue[idx] + stoneValue[idx + 1] - func(idx + 2, stoneValue, dp);
        int takeThree = INT_MIN;
        if(idx + 2 < n) takeThree = stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2] - func(idx + 3, stoneValue, dp);
        return dp[idx] = max({takeOne, takeTwo, takeThree});
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), -1);
        int val = func(0, stoneValue, dp);
        if(val > 0) return "Alice";
        else if(val < 0) return "Bob";
        else return "Tie";
    }
};