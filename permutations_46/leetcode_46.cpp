void func2(int idx, vector<int> &nums, vector<vector<int>> &answer){
        if(idx == nums.size()){
            answer.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            func2(idx + 1, nums, answer);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;
        vector<bool> freq(n, false);

        func2(0, nums, answer);
        return answer;
    }