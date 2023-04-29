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
        return q1[2] < q2[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        Disjoint_set ds(n);
        int q = queries.size();
        for(int i = 0; i < q; i++){
            queries[i].push_back(i);
        }
        int e = edgeList.size();
        sort(queries.begin(), queries.end(), compare);
        sort(edgeList.begin(), edgeList.end(), compare);
        int edgeIdx = 0;
        vector<bool> answer(q);
        for(int i = 0; i < q; i++){
            int limit = queries[i][2];
            int node1 = queries[i][0];
            int node2 = queries[i][1];
            int idx = queries[i][3];
            while(edgeIdx < e && edgeList[edgeIdx][2] < limit){
                int u = edgeList[edgeIdx][0];
                int v = edgeList[edgeIdx][1];
                if(ds.get_uparent(u) != ds.get_uparent(v)){
                    ds.union_by_rank(u, v);
                }
                edgeIdx++;
            }
            if(ds.get_uparent(node1) == ds.get_uparent(node2)) answer[idx] = true;
            else answer[idx] = false;
        }
        return answer;
    }
};