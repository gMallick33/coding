class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        target += 1;
        int n = letters.size();
        int idx = lower_bound(letters.begin(), letters.end(), target) - letters.begin();
        if(idx == n) return letters[0];
        else return letters[idx];
    }
};