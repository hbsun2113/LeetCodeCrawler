class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> um;
        for(const auto &p:paths){
            istringstream ins(p);
            string path;
            getline(ins,path,' ');
            string tmp;
            while(getline(ins,tmp,' ')){
                int pos=tmp.find_first_of('(');
                string file=tmp.substr(0,pos);
                string content=tmp.substr(pos);
                content.pop_back();
                um[content].push_back(path+"/"+file);
            }
        }
        
        vector<vector<string>> res;
        for(const auto &n:um){
            if(n.second.size()>1)
                res.push_back(n.second);
        }
        
        return res;
    }
};