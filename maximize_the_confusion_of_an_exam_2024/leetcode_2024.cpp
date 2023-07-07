class Solution {
public:
    int maxLenConfusion(string &s, int k, char ch){
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0, badChar = 0;
        while(right < n){
            if(s[right] != ch) badChar++;
            while(left < right && badChar > k){
                if(s[left] != ch) badChar--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        return max(maxLenConfusion(answerKey, k, 'T'), maxLenConfusion(answerKey, k, 'F'));
    }
};