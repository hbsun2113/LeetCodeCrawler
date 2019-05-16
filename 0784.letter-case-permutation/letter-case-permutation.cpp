class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string S) {
        dfs(S,0);
        return res;
    }
    
    void dfs(string S, int index){
        if(index==S.size()){
            res.push_back(S);
            return ;
        }
       
        dfs(S,index+1);
        
        if(S[index]>='a' && S[index]<='z'){
            S[index]+='A'-'a';
            dfs(S,index+1);
        }
        else if(S[index]>='A' && S[index]<='Z'){
            S[index]-='A'-'a';
            dfs(S,index+1);
        }
    }
};