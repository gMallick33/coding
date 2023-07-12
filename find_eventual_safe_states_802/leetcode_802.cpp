class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   
	   // kahn's algorithm method
	   vector<int> answer;
	   vector<int> in_degree(V, 0);
	   for(int i = 0; i < V; i++){
	       for(auto neigh: adj[i]){
	           in_degree[neigh]++;
	       }
	   }
	   queue<int> myqueue;
	   for(int i = 0; i < V; i++){
	       if(in_degree[i] == 0){
	           myqueue.push(i);
	           //answer.push_back(i);
	       }
	   }
	   while(!myqueue.empty()){
	       int front_elem = myqueue.front();
	       myqueue.pop();
	       answer.push_back(front_elem);
	       for(auto neigh: adj[front_elem]){
	           in_degree[neigh]--;
	           if(in_degree[neigh] == 0){
	               myqueue.push(neigh);
	           }
	       }
	   }
	   return answer;
	}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj_reverse[V];
        for(int i = 0; i < V; i++){
            for(auto neigh: graph[i]){
                adj_reverse[neigh].push_back(i);
            }
        }
        vector<int> answer = topoSort(V, adj_reverse);
        sort(answer.begin(), answer.end());
        return answer;
    }
};