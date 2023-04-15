class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod_beg = 1;
        int prod_end = 1;
        int max_prod = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            prod_beg *= nums[i];
            prod_end *= nums[nums.size() - 1 - i];
            
            max_prod = max({max_prod, prod_beg, prod_end});
            // cout << max_prod << " ";
            
            if(prod_beg == 0){
                prod_beg = 1;
            }
            if(prod_end == 0){
                prod_end = 1;
            }
        }
        return max_prod;
    }
};