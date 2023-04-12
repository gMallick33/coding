class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int val = abs(nums[i]);
            nums[val - 1] *= -1;
            if(nums[val - 1] > 0) return val;
        }
        return -1;
    }
};