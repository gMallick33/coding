class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> myStack;
        string token = "";
        for(int i = 0; i < n; i++){
            if(s[i] == ' ') continue;
            while(i < n && s[i] != ' '){
                token += s[i];
                i++;
            }
            myStack.push(token);
            token = "";
        }
        string answer = "";
        while(!myStack.empty()){
            string top = myStack.top();
            myStack.pop();
            answer += top;
            if(!myStack.empty()) answer += " ";
        }
        return answer;
    }
};