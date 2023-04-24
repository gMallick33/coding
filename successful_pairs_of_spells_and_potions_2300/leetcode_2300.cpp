class Solution {
public:
    int func(int idx, vector<int> &spells, vector<int> &potions, long long success){
        int low = 0;
        int n = potions.size();
        int high = n - 1;
        success -= 1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if((long long)spells[idx] * potions[mid] <= success){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return potions.size() - low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> answer;
        int n = spells.size();
        for(int i = 0; i < n; i++){
            int res = func(i, spells, potions, success);
            answer.push_back(res);
        }
        return answer;
    }
};