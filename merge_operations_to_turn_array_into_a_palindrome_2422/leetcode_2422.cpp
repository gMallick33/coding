class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int ops = 0;
        vector<long long> numsDup(nums.begin(), nums.end());
        while(left < right){
            if(numsDup[left] == numsDup[right]){
                left++;
                right--;
            }
            else if(numsDup[left] < numsDup[right]){
                numsDup[left + 1] += numsDup[left];
                left++;
                ops++;
            }
            else{
                numsDup[right - 1] += numsDup[right];
                right--;
                ops++;
            }
        }
        return ops;
    }
};