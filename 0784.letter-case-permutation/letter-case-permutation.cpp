class Solution {
public:
    // start 和 for 一般情况下是不共用的，这个错误犯了好几次了
    // 调试了很久！
    vector<string> res;
    vector<string> letterCasePermutation(string S) {
        dfs(S,0);
        return res;
    }
    
    void dfs(string S, int start){
        if(start==S.size()){
            res.push_back(S);
            return ;
        } 
        
        dfs(S,start+1); // 先保持初心，走到最后
        
        // 然后看看是否可以衍生其他版本
        if(islower(S[start])){ 
            S[start]=S[start]+('A'-'a');
            dfs(S,start+1);
        }
        else if(isupper(S[start])){
            S[start]=S[start]-('A'-'a');
            dfs(S,start+1);
        }
        
    }
};