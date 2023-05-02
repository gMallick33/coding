class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negativeCount = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) return 0;
            else if(nums[i] < 0) negativeCount++;
            else continue;
        }
        if(negativeCount % 2 == 0) return 1;
        else return -1;
    }
};