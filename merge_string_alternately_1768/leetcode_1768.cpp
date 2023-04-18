class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int i = 0;
        int j = 0;
        string answer = "";
        while(i < n && j < m){
            answer += word1[i];
            answer += word2[j];
            i++;
            j++;
        }
        while(i < n) {
            answer += word1[i];
            i++;
        }
        while(j < m) {
            answer += word2[j];
            j++;
        }
        return answer;
    }
};