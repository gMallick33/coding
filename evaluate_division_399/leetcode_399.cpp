class Solution {
public:
    unordered_map<string, unordered_map<string, double>> adjList;
    unordered_map<string, int> visited;

    bool dfs(string node, string dest, double &prod){
        if(node == dest) return true;
        visited[node] = 1;
        for(auto it: adjList[node]){
            string neigh = it.first;
            double val = it.second;
            if(!visited[neigh] && dfs(neigh, dest, prod)){
                prod *= val;
                return true;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        adjList.clear();
        for(int i = 0; i < equations.size(); i++){
            adjList[equations[i][0]][equations[i][1]] = values[i];
            adjList[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }

        vector<double> answer;
        for(auto i: queries){
            visited.clear();
            string src = i[0];
            string dest = i[1];
            double prod = 1;

            if(adjList.find(src) == adjList.end() || adjList.find(dest) == adjList.end()){
                answer.push_back(-1);
            }
            else if(dfs(src, dest, prod)){
                answer.push_back(prod);
            }
            else{
                answer.push_back(-1);
            }
        }
        return answer;
    }
};