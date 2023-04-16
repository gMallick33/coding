struct Node{
    Node* links[26];
    bool end_flag = false;
    bool contains_key(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put_char(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node *get_char(char ch){
        return links[ch - 'a'];
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->contains_key(word[i])){
                Node *temp = new Node();
                node->put_char(word[i], temp);
            }
            node = node->get_char(word[i]);
        }
        node->end_flag = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->links[word[i] - 'a']) return false;
            node = node->get_char(word[i]);
        }
        if(node->end_flag){
            return true;
        }
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i = 0; i < prefix.length(); i++){
            if(!node->links[prefix[i] - 'a']) return false;
            node = node->get_char(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */