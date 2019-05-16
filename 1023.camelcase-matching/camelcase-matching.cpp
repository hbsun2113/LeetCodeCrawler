class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> vec;
        for(const auto &query:queries){
            if(helper(query,pattern)) vec.push_back(true);
            else vec.push_back(false);
        }
        return vec;
    }
    
    bool helper(string query, string pattern){
        int i=0,j=0;
        unordered_map<char,int> um;
        bool flag=true;
        while(i!=query.size()){
            if(isupper(query[i])) um[query[i]]++;
            if(isupper(pattern[j]) && flag) um[pattern[j]]--;
            flag=false;
            if(query[i]==pattern[j]){
                j++;
                flag=true;
            }
            i++;
        }
        for(const auto &u:um){
            if(u.second!=0){
                //cout<<u.first<<" "<<u.second<<endl;
                return false;
            } 
        }
        //cout<<query<<" "<<pattern<<" "<<j<<" "<<pattern.size()-1<<endl;
        return j==pattern.size();
    }
};