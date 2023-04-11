class Solution {
public:
    string removeStars(string s) {
        string answer = "";
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '*') answer.pop_back();
            else answer += s[i];
        }
        return answer;
    }
};