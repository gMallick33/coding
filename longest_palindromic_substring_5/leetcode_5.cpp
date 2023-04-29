class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        int start;
        int maxi = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else{
                    if(s[i - 1] == t[j - 1]){
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        int ridx = i;
                        int idx = j - dp[i][j] + 1;
                        if(n - ridx + 1 == idx){
                            if(maxi < dp[i][j]){
                                start = i;
                                maxi = dp[i][j];
                            }
                        }
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        string answer = "";
        while(maxi){
            answer += s[start - 1];
            maxi--;
            start--;
        }
        return answer;
    }
};