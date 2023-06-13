class Solution {
public:
    // long long maxi = INT_MIN;
    // void func(int idx, vector<int> &nums, bool taken, long long prod){
    //     if(idx == nums.size()) {
    //         if(taken)
    //             maxi = max(maxi, prod);
    //         return;
    //     }
    //     func(idx + 1, nums, true, prod * nums[idx]);
    //     func(idx + 1, nums, taken, prod);
        
    // }
    long long maxStrength(vector<int>& nums) {
        
        // func(0, nums, false, 1);
        // return maxi;

        // sorting approach
        vector<int> neg, pos;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) neg.push_back(nums[i]);
            if(nums[i] > 0) pos.push_back(nums[i]);
        }
        long long prod = 1;
        sort(neg.begin(), neg.end());
        if(neg.size() <= 1 && pos.size() == 0){
            return *max_element(nums.begin(), nums.end());
        }
        if(neg.size() % 2 == 0){
            for(auto it: neg) prod *= it;
            for(auto it: pos) prod *= it;
            return prod;
        }
        else{
            for(int i = 0; i < neg.size() - 1; i++) prod *= neg[i];
            for(auto it: pos) prod *= it;
            return prod;
        }
        return prod;
    }
};