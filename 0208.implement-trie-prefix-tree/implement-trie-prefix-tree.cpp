// 终于自己完全做对了一遍：记住两个数据结构就行：isleaf和vector<Node*> child[26]
// https://leetcode.com/submissions/detail/213272823/
// https://leetcode.com/submissions/detail/185479876/
class Node {
public:    
    bool isleaf;
    vector<Node*> child;
    Node(){
        isleaf=false;
        child.resize(26);
    }
};

class Trie {
public:
    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *t=root;
        for(const auto &w:word){
            if(!t->child[w-'a'])
                t->child[w-'a']=new Node();
            t=t->child[w-'a'];
        }
        t->isleaf=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *t=root;
        for(const auto &w:word){
            if(!t->child[w-'a'])
                return false;
            t=t->child[w-'a'];
        }
        if(t->isleaf==false) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *t=root;
        for(const auto &w:prefix){
            if(!t->child[w-'a'])
                return false;
            t=t->child[w-'a'];
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