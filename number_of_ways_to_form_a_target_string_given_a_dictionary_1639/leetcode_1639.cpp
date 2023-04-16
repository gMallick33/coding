class Solution {
public:
    int mod = 1000000007;
    int func(int idx, int target_idx, vector<string> &words, string &target, vector<vector<int>> &freq, vector<vector<int>> &dp){
        if(target_idx == target.size()) return 1;
        if(idx == freq.size()) return 0;
        if(dp[idx][target_idx] != -1) return dp[idx][target_idx];
        int pick_ways = 0;
        char ch = target[target_idx];
        if(freq[idx][ch - 'a'] != 0){
            pick_ways = (func(idx + 1, target_idx + 1, words, target, freq, dp) * (long long)freq[idx][ch - 'a']) % mod;
        }
        int not_pick_ways = func(idx + 1, target_idx, words, target, freq, dp) % mod;
        int total_ways = (pick_ways + not_pick_ways) % mod;
        return dp[idx][target_idx] = total_ways;
    }
    int numWays(vector<string>& words, string target) {
        int m = words.size();
        int n = words[0].size();
        int t = target.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char ch = words[i][j];
                freq[j][ch - 'a']++;
            }
        }
        vector<vector<int>> dp(n, vector<int>(t, -1));
        return func(0, 0, words, target, freq, dp);
    }
};