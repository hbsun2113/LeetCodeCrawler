class Solution {
public:
    // 自己写的，一把过！
    unordered_map<string,vector<string>> um;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(const auto& a:allowed)
            um[a.substr(0,2)].push_back(a.substr(2));
        return dfs(bottom,0,"");
    }
    
    
    // bottom是当前的底，index是bottom的索引，part是正在构建的新底
    bool dfs(string bottom,int index,string part){
        if(bottom.size()<=1) return true;
        if(index==bottom.size()-1){
            string tmp;
            return dfs(part,0,tmp);
        }
        string key=bottom.substr(index,2);
        auto it=um.find(key);
        if(it==um.end()) return false;
        for(auto &val:um[key]){
            if(dfs(bottom,index+1,part+val)) return true;
        }
        return false;
    }
    
    
    
    
};