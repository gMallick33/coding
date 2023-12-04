class Solution {
public:
    string largestGoodInteger(string nums) {
        int result = -1;
        int n = nums.length();
        for(int i = 0; i + 2 < n; i++) {
            if(nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
                result = max(result, nums[i] - '0');
            }
        }
        return result == -1 ? "" : string(3, result + '0');
    }
};