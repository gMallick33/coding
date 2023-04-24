class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> my_map;
        int n = nums2.size();
        for(int i = 0; i < n; i++){
            my_map[nums2[i]] = i;
        }

        vector<int> temp(n, -1);
        stack<int> my_stack;
        my_stack.push(0);
        for(int i = 1; i < n; i++){
            if(my_stack.empty()) my_stack.push(i);
            else{
                while(!my_stack.empty() && nums2[my_stack.top()] < nums2[i]){
                    temp[my_stack.top()] = i;
                    my_stack.pop();
                }
                my_stack.push(i);
            }
        }
        vector<int> answer;
        for(int i = 0; i < nums1.size(); i++){
            int idx = my_map[nums1[i]];
            int res_idx = temp[idx];
            if(res_idx == -1) answer.push_back(-1);
            else answer.push_back(nums2[res_idx]);
        }
        return answer;
    }
};