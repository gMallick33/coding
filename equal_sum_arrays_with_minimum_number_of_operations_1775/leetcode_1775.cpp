class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if(sum1 == sum2) return 0;
        if(sum2 < sum1) return minOperations(nums2, nums1);

        if(m > 6 * n) return -1;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int high = m - 1;
        int low = 0;

        int ops = 0;
        int diff = sum2 - sum1;
        while(low < n || high >= 0){
            int change1 = 0,  change2 = 0;

            if(low < n) change1 = 6 - nums1[low];
            if(high >= 0) change2 = nums2[high] - 1;

            if(change1 >= change2){
                diff -= change1;
                low++;
            }
            else{
                diff -= change2;
                high--;
            }
            ops++;
            if(diff <= 0) break;
        }
        return ops;
    }
};