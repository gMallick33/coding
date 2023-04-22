class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 2;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            int neigh = mid ^ 1;
            if(nums[mid] == nums[neigh]) low = mid + 1;
            else high = mid - 1;
        }
        return nums[low];
    }
};