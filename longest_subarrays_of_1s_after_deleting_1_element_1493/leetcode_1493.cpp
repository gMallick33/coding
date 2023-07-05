class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int currLen = 0, prevLen = 0, maxLen = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]) currLen++;
            else{
                prevLen = currLen;
                currLen = 0;
            }
            maxLen = max(maxLen, prevLen + currLen);
        }
        if(maxLen == n) return n - 1;
        else return maxLen;
    }
};