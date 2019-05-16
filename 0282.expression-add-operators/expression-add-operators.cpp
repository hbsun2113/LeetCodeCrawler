class Solution {
public:
    // http://www.cnblogs.com/grandyang/p/4814506.html
    vector<string> res; 
    vector<string> addOperators(string num, int target) {
        dfs(num,target,0,0,"");
        return res;
    }

    void dfs(string num, long long target, long long curr, long long diff, string out){
        if(num.size()==0 && curr==target){
            res.push_back(out);
            return ;
        }
        for(int i=1;i<=num.size();i++){
            string first=num.substr(0,i);
            if(first.size()>1 && first[0]=='0') continue;
            string second=num.substr(i);
            if(out.size()==0){
                dfs(second,target,curr+stoll(first),stoll(first),first);
                continue;
            }
            dfs(second,target,curr+stoll(first),stoll(first),out+'+'+first);
            dfs(second,target,curr-stoll(first),-stoll(first),out+'-'+first);
            dfs(second,target,curr-diff+diff*stoll(first),diff*stoll(first),out+'*'+first);
        }
    }
};