class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int maxi = nums[0];
        for(int i = 1; i < n; i++){
            int temp = sum + nums[i];
            if(temp < nums[i]){
                sum = nums[i];
            }
            else sum = temp;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};