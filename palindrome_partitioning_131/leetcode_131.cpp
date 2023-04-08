class Solution {
public:
    bool is_palindrome(string s, int i, int j){
        while(i <= j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    
    void func(int idx, vector<string> &answer_partial, vector<vector<string>> &answer, string s){
        if(idx == s.length()){
            answer.push_back(answer_partial);
            return;
        }
        for(int i = idx; i < s.length(); i++){
            if(is_palindrome(s, idx, i)){
                answer_partial.push_back(s.substr(idx, i - idx + 1));
                func(i + 1, answer_partial, answer, s);
                answer_partial.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> answer_partial;
        func(0, answer_partial, answer, s);
        return answer;
    }
};