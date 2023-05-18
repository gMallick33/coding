class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<int> rank(n, 0);
        for(int i = 0; i < e; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            rank[v]++;
        }
        vector<int> answer;
        for(int i = 0; i < n; i++){
            if(rank[i] == 0) answer.push_back(i);
        }
        return answer;
    }
};