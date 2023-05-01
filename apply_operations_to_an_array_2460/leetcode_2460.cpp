class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i + 1] = 0;
                nums[i] *= 2;
            }
        }
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[idx] = nums[i];
                idx++;
            }
        }
        while(idx < n){
            nums[idx] = 0;
            idx++;
        }
        return nums;
    }
};