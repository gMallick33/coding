class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long pre = 0;
        long long res = 0;
        
        for (long long x: nums) {
            res = (res + (x * x % mod) * x % mod + (x * x % mod) * pre % mod) % mod;
            pre = (pre * 2 + x) % mod;
    }
        return res;
    }
};