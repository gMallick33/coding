class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> my_stack;

        int pop_i = 0;
        for(int i = 0; i < n ;i++){
            if(popped[pop_i] != pushed[i]){
                my_stack.push(pushed[i]);
            }
            else{
                pop_i++;
                while(!my_stack.empty() && my_stack.top() == popped[pop_i]){
                    my_stack.pop();
                    pop_i++;
                }
            }
        }
        if(my_stack.empty()) return true;
        else return false;
    }
};