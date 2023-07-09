/*
firstChar == major element (assuming it occurs more time than other, which may not be true)
secondChar == minor element (assuming it occurs less time than other, which may not be true)
restCount > 0 is important.
*/
class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        vector<int> freq(26);
        for(int i = 0; i < n; i++) freq[s[i] - 'a']++;
        int maxi = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                char firstChar = 'a' + i;
                char secondChar = 'a' + j;
                int firstCount = 0;
                int secondCount = 0;
                int restCount = freq[j];
                if(i == j || !freq[i] || !freq[j]) continue;
                for(int k = 0; k < n; k++){
                    
                    if(s[k] == firstChar) firstCount++;
                    if(s[k] == secondChar) {
                        secondCount++;
                        restCount--;
                    }
                    if(secondCount > 0){
                        maxi = max(maxi, firstCount - secondCount);
                    }
                    if(firstCount < secondCount && restCount > 0){
                        firstCount = 0;
                        secondCount = 0;
                    }
                    // cout << firstChar << ": " << firstCount << " " << secondChar << ": " << secondCount << endl;
                    // cout << "maxi: " << maxi << endl;
                }
            }
        }
        return maxi;
    }
};