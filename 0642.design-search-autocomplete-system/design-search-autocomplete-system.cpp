class Node{
public:    
    unordered_map<char,Node*> um;
    int time=0;
};
// ??????????????wrong answer??????
class AutocompleteSystem {
public:
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i=0;i<sentences.size();i++){
            auto cur=root;
            for(const auto &c:sentences[i]){
                if(cur->um.find(c)==cur->um.end()) cur->um[c]=new Node();
                cur=cur->um[c];
            }
            cur->time=times[i];
        }
    }
    
    vector<string> input(char c) {
        if(c=='#'){
            now->time++;
            now=root;
            tmp="";
            return {};  // ???# ,???????????
        } 
        
        if(now->um.find(c)==now->um.end()){
            now->um[c]=new Node(); // ?????????????????
            now=now->um[c];
            return {};
        } 
        
        vector<pair<int,string>> cand;  // ?????????????????????????????
        now=now->um[c];
        tmp+=c;

        dfs(now,cand,tmp);
        
        auto cmp=[](pair<int,string> &a, pair<int,string> &b){
            if(a.first!=b.first) return a.first>b.first;
            else return a.second<b.second;
        };
        sort(cand.begin(),cand.end(),cmp);
        
        vector<string> res;
        for(int i=0;i<min(3,(int)cand.size());i++) res.push_back(cand[i].second);
        return res;
    }
    
    void dfs(Node *root, vector<pair<int,string>> &cand, string tmp){
        if(root->time!=0){
            cand.push_back(make_pair(root->time,tmp));
        }
        for(auto &[c,n]:root->um){
            dfs(n,cand,tmp+c);
        }
    }
    
    // ????????
    Node *root=new Node();
    string tmp="";
    Node* now=root;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */