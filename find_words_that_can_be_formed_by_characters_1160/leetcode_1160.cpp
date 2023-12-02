class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       vector<int> charCount(26, 0);
       for(char ch: chars) charCount[ch - 'a']++;
       int n = words.size();
       int answer = 0;
       for(int i = 0; i < n; i++){
           if(canForm(words[i], charCount)) answer += words[i].size();
       }
       return answer;
    }

    bool canForm(string &str, vector<int> &charCount) {
        vector<int> tempCount(26, 0);
        for(char ch: str) {
            tempCount[ch - 'a']++;
            if(tempCount[ch - 'a'] > charCount[ch - 'a']) return false;
        }
        return true;
    }
};