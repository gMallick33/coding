class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        while(right < n){
            sum += nums[right++];
            while(sum >= target){
                minLen = min(minLen, right - left);
                sum -= nums[left++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};