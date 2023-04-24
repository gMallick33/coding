class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> my_stack;
        vector<int> answer(n, -1);
        for(int i = 0; i < 2 * n; i++){
            int idx = i >= n ? i - n: i;
            while(!my_stack.empty() && nums[idx] > nums[my_stack.top()]){
                int top_idx = my_stack.top();
                my_stack.pop();
                answer[top_idx] = nums[idx];
            }
            if(answer[idx] == -1) my_stack.push(idx);
        }
        return answer;
    }
};