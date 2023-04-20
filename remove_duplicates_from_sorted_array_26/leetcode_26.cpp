class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = nums.size();
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                auto x = nums.begin() + i;
                nums.erase(x);
                count--;
                i--;
            }
        }
        return count;
    }
};