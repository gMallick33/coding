class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        for(int i = 0; i < n - 1; i++){
            
            cout << "nums[i]: " << nums[i] << " " << "nums[i + 1]: " << nums[i + 1] << endl;
            cout << "nums[i + 1] - nums[i] == " << nums[i + 1] - nums[i] << endl;
            if(nums[i + 1] - nums[i] != 1) continue;
            else{
                int currSize = 2;
                int k = i + 1;
                int mul = 1;
                while(k < n - 1 && nums[k + 1] - nums[k] == -1 * mul){
                    cout << "inside while: " << k << " " << maxi << endl;
                    currSize++;
                    mul *= -1;
                    k++;
                }
                maxi = max(maxi, currSize);
            }
        }
        return maxi;
    }
};