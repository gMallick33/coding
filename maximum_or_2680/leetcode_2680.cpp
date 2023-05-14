class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        int preOr = 0;
        int suffOr = 0;
        vector<int> prefix(n), suffix(n);
        for(int i = 0; i < n; i++){
            preOr |= nums[i];
            prefix[i] = preOr;
        }
        for(int i = n - 1; i >= 0; i--){
            suffOr |= nums[i];
            suffix[i] = suffOr;
        }
        long long maxi = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                long long elem = nums[i];
                elem <<= k;
                int s = 0;
                if(i + 1 < n) s = suffix[i + 1];
                maxi = max(maxi, elem | s);
            }
            else if(i == n - 1){
                long long elem = nums[i];
                elem <<= k;
                int p = 0;
                if(i - 1 >= 0) p = prefix[i - 1];
                maxi = max(maxi, elem | p);
            }
            else{
                long long elem = nums[i];
                elem <<= k;
                maxi = max(maxi, elem | prefix[i - 1] | suffix[i + 1]);
            }
        }
        return maxi;
    }
};