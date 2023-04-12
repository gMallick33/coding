class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx;
        for(idx = n - 2; idx >= 0; idx--){
            if(nums[idx] < nums[idx + 1]) break;
        }
        if(idx == -1){
            sort(nums.begin(), nums.end());
            return;
        }

        for(int i = n - 1; i >= 0; i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }
        sort(nums.begin() + idx + 1, nums.end());
    }
};