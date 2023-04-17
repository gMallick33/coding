class Solution {
public:
    vector<vector<int>> answer;
    void func(int idx, vector<int> &nums, vector<int> answer_partial){
        if(idx == nums.size()){
            sort(answer_partial.begin(), answer_partial.end());
            answer.push_back(answer_partial);
            return;
        }
        
        func(idx + 1, nums, answer_partial);
        answer_partial.push_back(nums[idx]);
        func(idx + 1, nums, answer_partial);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> answer_partial;
        func(0, nums, answer_partial);
        return answer;
    }
};