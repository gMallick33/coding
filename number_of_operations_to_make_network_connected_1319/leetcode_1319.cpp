class Disjoint_set{
    
    public:
    vector<int> parent, rank;
    Disjoint_set(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }
    
    int get_uparent(int node){
        if(node == parent[node]) return node;
        else{
            return parent[node] = get_uparent(parent[node]);
        }
    }
    
    void union_by_rank(int u, int v){
        int u_parent = get_uparent(u);
        int v_parent = get_uparent(v);
        if(u_parent == v_parent) return;
        else{
            if(rank[u_parent] < rank[v_parent]){
                parent[u_parent] = v_parent;
            }
            else if(rank[v_parent] < rank[u_parent]){
                parent[v_parent] = u_parent;
            }
            else{
                parent[u_parent] = v_parent;
                rank[u_parent]++;
            }
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint_set ds(n);
        int c = connections.size();
        for(int i = 0; i < c; i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if(ds.get_uparent(u) != ds.get_uparent(v)){
                ds.union_by_rank(u, v);
            }
        }
        int connected_comp = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) connected_comp++;
        }
        if(c < n - 1) return -1;
        else return connected_comp - 1;
    }
};