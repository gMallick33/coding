class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        int count = 1;
        temp.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                count++;
            }
            else{
                auto ind = lower_bound(temp.begin(), temp.end(), nums[i]);
                temp[ind - temp.begin()] = nums[i];
            }
        }
        return count;
    }
};