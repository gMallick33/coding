class Solution {
public:
    class Disjoint_set{
        vector<int> parent, rank;
            public:
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
    static bool compare(const vector<int> &q1, const vector<int> &q2){
        return q1[0] > q2[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Disjoint_set dsAlice(n + 1);
        Disjoint_set dsBob(n + 1);

        int aliceEdges = 0;
        int bobEdges = 0;
        int removedEdges = 0;
        sort(edges.begin(), edges.end(), compare);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][1];
            int v = edges[i][2];
            if(edges[i][0] == 3){
                if(dsAlice.get_uparent(u) != dsAlice.get_uparent(v)){
                    dsAlice.union_by_rank(u, v);
                    dsBob.union_by_rank(u, v);

                    aliceEdges++;
                    bobEdges++;
                }
                else removedEdges++;
            }
            else if(edges[i][0] == 1){
                if(dsAlice.get_uparent(u) != dsAlice.get_uparent(v)){
                    dsAlice.union_by_rank(u, v);
                    aliceEdges++;
                }
                else removedEdges++;
            }
            else{
                if(dsBob.get_uparent(u) != dsBob.get_uparent(v)){
                    dsBob.union_by_rank(u, v);
                    bobEdges++;
                }
                else removedEdges++;
            }
        }
        if(aliceEdges == n - 1 && bobEdges == n - 1) return removedEdges;
        else return -1;
    }
};