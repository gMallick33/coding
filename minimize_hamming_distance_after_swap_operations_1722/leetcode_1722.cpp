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
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        Disjoint_set ds(n);
        for(int i = 0; i < allowedSwaps.size(); i++){
            int u = allowedSwaps[i][0];
            int v = allowedSwaps[i][1];
            if(ds.get_uparent(u) != ds.get_uparent(v)) ds.union_by_rank(u, v);
        }
        map<int, map<int, int>> myMap;
        for(int i = 0; i < n; i++){
            myMap[ds.get_uparent(i)][source[i]]++;
        }
        int hammingDistance = n;
        for(int i = 0; i < n; i++){
            int targetElem = target[i];
            if(myMap[ds.get_uparent(i)].find(targetElem) == myMap[ds.get_uparent(i)].end()) continue;
            else{
                hammingDistance--;
                myMap[ds.get_uparent(i)][targetElem]--;
                if(myMap[ds.get_uparent(i)][targetElem] == 0) myMap[ds.get_uparent(i)].erase(targetElem);
            }
        }
        return hammingDistance;
    }
};