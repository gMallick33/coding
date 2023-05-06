class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        vector<int> pre;
        pre.push_back(1);
        for(int i = 1; i <= 1e5; i++){
            pre.push_back((pre.back() << 1) % mod);
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int answer = 0;
        while(low <= high){
            while(low <= high && nums[low] + nums[high] > target) high--;
            if(high >= low){
                answer = (answer + pre[high - low]) % mod;
                low++;
            }
        }
        return answer;
    }
};