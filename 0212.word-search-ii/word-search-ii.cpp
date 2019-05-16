//看了别人的代码，然后自己默写了一遍，可能只能用线段树吧
// https://leetcode.com/problems/word-search-ii/discuss/59841/My-AC-very-clean-C++-code
class TrieNode{
public:
    bool is_end;
    vector<TrieNode*> child;
    TrieNode(){
        is_end=false;
        child=vector<TrieNode*>(26,nullptr);
    }
};

class Trie{
public:
    TrieNode *root;
    
    Trie(vector<string> words){
        root=new TrieNode();
        for(const auto &w:words) addWord(w); //直接用words建立树，这样在使用dfs的时候会减少搜索空间。这么做相当于在words的空间中搜索，而暴力解法是在boards中搜索。
    }
    
    void addWord(const string &word){ 
        TrieNode *curr=root;
        for(const auto&w:word){
            int index=w-'a';
            if(curr->child[index]==nullptr)
                curr->child[index]=new TrieNode();
            curr=curr->child[index];
            cout<<index<<endl;
        }
        curr->is_end=true;
    }
    
};


class Solution {
public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        unordered_set<string> tmp;
        
        Trie tree(words);
        
        string s;
        for(int x=0;x<board.size();x++){
            for(int y=0;y<board[0].size();y++){
                judge(x,y,board,tmp,tree.root,s);
            }
        }
        
        for(const auto &t:tmp) result.emplace_back(t);
        return result;
    }
    
    void judge(int x,int y,vector<vector<char>>& board,unordered_set<string> &tmp, TrieNode *root, string s){
        if(!((x>=0) && (x<board.size()) && (y>=0) && (y<board[0].size()) && (board[x][y]!=' '))) return ;

        //if(root->is_end) tmp.emplace(s); 不可以放在这里，放在这里是要在进入子函数中才去判断，这样可能直接被前面的if语句杀死，都到不了这里了。
        
        int index=board[x][y]-'a';
        if(root->child[index]==nullptr) return;
        
        char c='a'+index;
        s+=c;
        root=root->child[index];
        if(root->is_end) tmp.emplace(s); //必须要放在这里，遍历到这里马上就判断。
        board[x][y]=' ';
    
        judge(x+1,y,board,tmp,root,s);
        judge(x-1,y,board,tmp,root,s);
        judge(x,y+1,board,tmp,root,s);
        judge(x,y-1,board,tmp,root,s);
        
        board[x][y]=c;
    }
};



// 自己的暴力解法，会超时。
// class Solution {
// public:
//     unordered_set<string> us;
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         vector<string> result;
//         unordered_set<string> tmp;
//         vector<vector<bool>> mask(board.size(),vector<bool>(board[0].size(),true));
//         string s;xx
//         for(const auto &w:words) us.emplace(w);
//         for(int x=0;x<board.size();x++){
//             for(int y=0;y<board[0].size();y++){
//                 judge(x,y,mask,board,s,tmp);
//             }
//         }
        
//         /*
//         sort(result.begin(), result.end());
// 	    auto new_end = unique(result.begin(), result.end());//"删除"相邻的重复元素
// 	    result.erase(new_end, result.end());//删除(真正的删除)重复的元素
//         */
        
//         for(const auto &t:tmp) result.emplace_back(t);
//         return result;
//     }
    
//     void judge(int x,int y,vector<vector<bool>>& mask,vector<vector<char>>& board,string s,unordered_set<string> &tmp){
//         if(!((x>=0) && (x<mask.size()) && (y>=0) && (y<mask[0].size()) && (mask[x][y]))) return ;
//         // cout<<x<<" "<<y<<endl;
//         s+=board[x][y];
//         if(us.count(s)){
//             // cout<<s<<" "<<x<<" "<<y<<endl;
//             if(tmp.count(s)) return;
//             tmp.emplace(s);
//         }
//         mask[x][y]=false;
    
//         judge(x+1,y,mask,board,s,tmp);
//         judge(x-1,y,mask,board,s,tmp);
//         judge(x,y+1,mask,board,s,tmp);
//         judge(x,y-1,mask,board,s,tmp);
       
//         mask[x][y]=true;
//     }
// };