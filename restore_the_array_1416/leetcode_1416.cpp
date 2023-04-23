class Solution {
public:
    int mod = 1e9 + 7;
    int func(int idx, string &s, int k, vector<int> &dp){
        if(idx == s.length()) return 1;
        int num_ways = 0;
        if(dp[idx] != -1) return dp[idx];
        for(int i = idx; i < s.length(); i++){
            string num_string = s.substr(idx, i - idx + 1);
            long long num = stod(num_string);
            if(num == 0) break;
            if(num <= k) {
                num_ways += func(i + 1, s, k, dp);
                num_ways = num_ways % mod;
            }
            else break;
        }
        return dp[idx] = num_ways;
    }
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n, -1);
        return func(0, s, k, dp);
    }
};