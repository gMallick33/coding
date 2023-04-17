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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
    for(int i = 0; i < nums.size(); i++){
        trie.insert(nums[i]);
    }
    int maxi = 0;
    for(int i = 0; i < nums.size(); i++){
        maxi = max(maxi, trie.get_max(nums[i]));
    }
    return maxi;
    }
};