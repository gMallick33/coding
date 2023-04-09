class Solution {
public:
    int func(int idx, vector<int> temp, vector<int> &dp){
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int taken = temp[idx] + func(idx - 2, temp, dp);
        int not_taken = func(idx - 1, temp, dp);

        return dp[idx] = max(taken, not_taken);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> temp1, temp2;
        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);
        return max(func(n - 2, temp1, dp1), func(n - 2, temp2, dp2));
        
    }
};