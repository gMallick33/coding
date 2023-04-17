struct Node{
    Node* links[2];
    bool contains_bit(int bit){
        return links[bit] != NULL;
    }
    Node* get_bit(int bit){
        return links[bit];
    }
    void put_bit(int bit, Node* node){
        links[bit] = node;
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(!node->contains_bit(bit)){
                node->put_bit(bit, new Node());
            }
            node = node->get_bit(bit);
        }
    }
    int get_max(int num){
        Node* node = root;
        int max_num = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node->contains_bit(1 - bit)){
                max_num = max_num | (1 << i);
                node = node->get_bit(1 - bit);
            }
            else{
                node = node->get_bit(bit);
            }
        }
        return max_num;
    }
};
class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> answer(q);
        vector<vector<int>> num_ind_query;
        for(int i = 0; i < q; i++){
            int num = queries[i][1];
            int query = queries[i][0];
            num_ind_query.push_back({num, i, query});
        }
        sort(num_ind_query.begin(), num_ind_query.end());
        sort(nums.begin(), nums.end());
        Trie trie;
        int n = nums.size();
        int ind = 0;

        for(int i = 0; i < q; i++){
            int mi = num_ind_query[i][0];
            int xi = num_ind_query[i][2];
            int indi = num_ind_query[i][1];

            while(ind < n && nums[ind] <= mi){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind == 0) answer[indi] = -1;
            else{
                int maxi = trie.get_max(xi);
                answer[indi] = maxi;
            }
        }
        return answer;
    }
};