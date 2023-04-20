class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> unique_triplets;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i <= n - 3; i++){
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    unique_triplets.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(sum < 0) l++;
                else r--;
            }
        }
        for(auto it: unique_triplets){
            answer.push_back(it);
        }
        return answer;
    }
};