class Node{
public:    
    bool end=false;
    vector<Node*> next;
    
    Node(){
        next.clear();
        next.resize(26,nullptr);
    }
};

class WordDictionary {
public:
    Node *root=new Node();
    
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto cur=root;
        for(const auto &c:word){
            if(cur->next[c-'a']==nullptr) cur->next[c-'a']=new Node();
            cur=cur->next[c-'a'];
        }
        cur->end=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word,0,root);
    }
    
    bool dfs(string &s, int i, Node* cur){
        if(i==s.size()){
            if(cur->end) return true;
            else return false;
        } 
        
        if(s[i]=='.'){
            for(auto &v:cur->next){
                if(v==nullptr) continue;
                if(dfs(s,i+1,v)) return true;
            }
            return false;
        }
        
        if(cur->next[s[i]-'a']==nullptr) return false;
        return dfs(s,i+1,cur->next[s[i]-'a']);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */