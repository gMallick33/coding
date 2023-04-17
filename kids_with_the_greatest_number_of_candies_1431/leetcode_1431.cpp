class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> answer;
        int maxi = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        for(int i = 0; i < n; i++){
            int temp = candies[i] + extraCandies;
            if(temp >= maxi) answer.push_back(true);
            else answer.push_back(false);
        }
        return answer;
    }
};