class Solution {
public:
    int dp[301];
    bool func(int i, string s, set<string> wordset){
        if(i == s.length()) return true;
        if(dp[i] != -1) return dp[i];
        string temp;
        for(int j = i; j < s.length(); j++){
            temp += s[j];
            if(wordset.find(temp) != wordset.end()){
                if(func(j + 1, s, wordset)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordset;
        for(auto st: wordDict){
            wordset.insert(st);
        }

        memset(dp, -1, sizeof dp);
        return func(0, s, wordset);
    }
};