class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if(n == 2) return true;
        int max_elem = *max_element(arr.begin(), arr.end());
        int min_elem = *min_element(arr.begin(), arr.end());
        if(max_elem - min_elem == 0) return true;
        if((max_elem - min_elem) % (n - 1) != 0) return false;
        int diff = (max_elem - min_elem) / (n - 1);
        unordered_set<int> arrSet;
        for(int i = 0; i < n; i++){
            if((arr[i] - min_elem) % diff != 0) return false;
            else{
                arrSet.insert(arr[i]);
            }
        }
        if(arrSet.size() == n) return true;
        else return false;
    }
};