class Solution {
public:
    int merge(int start, int mid, int end, vector<int> &nums){
        int i = start, j = mid + 1, k = 0;
        vector<int> temp(end - start + 1);
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp[k] = nums[i];
                i++;
                k++;
            }
            else{
                temp[k] = nums[j];
                j++;
                k++;
            }
        }
        while(i <= mid){
            temp[k] = nums[i];
            k++;
            i++;
        }
        while(j <= end){
            temp[k] = nums[j];
            k++;
            j++;
        }

        i = start, j = mid + 1;
        int rev_pairs = 0;
        while(i <= mid){
            while(j <= end && (long long)nums[i] > 2 * (long long)nums[j]){
                j++;
            }
            i++;
            rev_pairs += j - 1 - mid;
        }
        k = 0;
        for(int i = start; i <= end; i++){
            nums[i] = temp[k];
            k++;
        }
        return rev_pairs;
    }
    int merge_sort(int start, int end, vector<int> &nums){
        int rev_pairs = 0;
        if(start < end){
            int mid = (end - start) / 2 + start;
            rev_pairs += merge_sort(start, mid, nums);
            rev_pairs += merge_sort(mid + 1, end, nums);
            rev_pairs += merge(start, mid, end, nums);
        }
        return rev_pairs;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge_sort(0, n - 1, nums);
    }
};