class Solution {
public:
    // https://leetcode.com/problems/simplify-path/discuss/25680/C++-10-lines-solution
    string simplifyPath(string path) {
        vector<string> his;
        string res;
        istringstream ss(path);
        string tmp;
        while(getline(ss,tmp,'/')){
            if(tmp=="" || tmp==".") continue;
            if(tmp==".." && !his.empty()) his.pop_back();
            if(tmp!="..") his.push_back(tmp);
        }
        if(his.empty()) return "/";
        for(const auto h:his){
            res+="/"+h;
        }
        return res;
    }
};