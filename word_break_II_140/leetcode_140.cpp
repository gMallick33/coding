class Solution {
public:
    vector<string> answer;
    void func(int idx, string &s, unordered_set<string> &st, string curr){
        if(idx == s.length()){
            curr.pop_back();
            answer.push_back(curr);
            return;
        }
        
        for(int i = idx; i < s.length(); i++){
            string sub = s.substr(idx, i - idx + 1);
            if(st.find(sub) != st.end()){
                func(i + 1, s, st, curr + sub + " ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string a:wordDict) st.insert(a);
        func(0, s, st, "");
        return answer;
    }
};