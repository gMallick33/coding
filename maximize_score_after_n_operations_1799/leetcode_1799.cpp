class Solution {
public:
    int func(vector<int> &nums, int mask, int ops, vector<int> &dp, vector<vector<int>> &gcd){
        int m = nums.size();
        int n = m / 2;
        if(ops > n) return 0;
        if(dp[mask] != -1) return dp[mask];
        int score = 0;
        for(int i = 0; i < m; i++){
            if(mask & (1 << i)) continue;
            for(int j = i + 1; j < m; j++){
                if(mask & (1 << j)) continue;
                int newMask = (1 << i) | (1 << j) | mask;
                score = max(score, ops * gcd[i][j] + func(nums, newMask, ops + 1, dp, gcd));
            }
        }
        return dp[mask] = score;
    }
    int maxScore(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(1 << 14, -1);
        vector<vector<int>> gcd(size, vector<int>(size));
        for(int i = 0; i < size; i++){
            for(int j = i; j < size; j++){
                gcd[i][j] = gcd[j][i] = __gcd(nums[i], nums[j]);
            }
        }
        return func(nums, 0, 1, dp, gcd);
    }
};