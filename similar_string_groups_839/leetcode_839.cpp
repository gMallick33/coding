class Solution {
public:
    bool isSimilar(string &str1, string &str2){
        int len = str1.size();
        int notSameCount = 0;
        for(int i = 0; i < len; i++){
            if(str1[i] != str2[i]) notSameCount++;
        }
        if(notSameCount == 0 || notSameCount == 2) return true;
        else return false;
    }
    void dfs(int i, vector<string> &strs, vector<bool> &visited){
        visited[i] = true;
        int n = strs.size();
        for(int j = 0; j < n; j++){
            if(!visited[j]){
                if(isSimilar(strs[i], strs[j])) dfs(j, strs, visited);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<bool> visited(n, false);
        int groups = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            else{
                groups++;
                dfs(i, strs, visited);
            }
        }
        return groups;
    }
};