class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') my_stack.push(s[i]);
            else{
                if(my_stack.empty()) return false;
                else{
                    if(s[i] == ')'){
                        if(my_stack.top() == '(') my_stack.pop();
                        else return false;
                    }
                    else if(s[i] == '}'){
                        if(my_stack.top() == '{') my_stack.pop();
                        else return false;
                    }
                    else{
                        if(my_stack.top() == '[') my_stack.pop();
                        else return false;
                    }
                }
            }
        }
        if(my_stack.empty()) return true;
        return false;
    }
};