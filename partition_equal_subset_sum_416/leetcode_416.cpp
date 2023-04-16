class Solution {
public:
    bool func(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == 0){
            if(nums[ind] == sum)
                return true;
            else
                return false;
        }
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        bool take = false;
        if(nums[ind] == sum)
            return true;
        else if(nums[ind] < sum){
            take = take || func(ind - 1, sum - nums[ind], nums, dp);
        }
        bool not_take = func(ind - 1, sum, nums, dp);
        dp[ind][sum] = take || not_take;
        return dp[ind][sum];
    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % 2 == 1){
            return false;
        }
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        return func(n - 1, sum / 2, nums, dp);
    }
};