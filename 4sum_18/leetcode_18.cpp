class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        int n = nums.size();
        for(int i = 0; i <= n - 4; i++){
            for(int j = i + 1; j <= n - 3; j++){
                long long remaining_sum = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;
                while(left < right){
                    long long sum = nums[left] + nums[right];
                    if(sum == remaining_sum){
                        cout << i << " " << j  << " " << left << " " << right << endl;
                        answer.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int left_val = nums[left];
                        int right_val = nums[right];
                        while(left < right && nums[left] == left_val) left++;
                        while(left < right && nums[right] == right_val) right--;

                    }
                    else if(sum < remaining_sum){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
                while(j + 1 < n && nums[j] == nums[j + 1]) j++;
            }
            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return answer;
    }
};