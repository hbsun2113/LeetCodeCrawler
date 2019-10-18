class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<unordered_map<char,int>> vec(n+1);
        unordered_map<char,int> um;
        vec[0]=um;
        for(int i=0;i<n;i++){
            um[s[i]]++;
            vec[i+1]=um;
        }
        vector<bool> res(queries.size());
        for(int i=0;i<queries.size();i++){
            const auto &v=queries[i];
            int l=v[0],r=v[1]+1,k=v[2];
            int cnt=0;
            for(const auto &n:vec[r]){
                auto key=n.first;
                int cha=vec[r][key]-vec[l][key];
                if(cha%2==1) cnt++;
                // cout<<key<<" "<<vec[r][key]<<" "<<vec[l][key]<<" "<<cha<<" "<<cnt<<endl;
            }
            if(cnt/2>k) res[i]=false;
            else res[i]=true;
        }
        // for(int i=0;i<queries.size();i++){
        //     const auto &v=queries[i];
        //     int l=v[0],r=v[1],k=v[2];
        //     string t=s.substr(l,r-l+1);
        //     if(check(t,k)) res[i]=true;
        //     else res[i]=false;
        // }
        return res;
    }
    
    // bool check(string &t,int k,){
    //     if(t.size()==1) return true;
    //     unordered_set<char> us;
    //     for(const auto &c:t){
    //         if(us.find(c)!=us.end()) us.erase(c);
    //         else us.insert(c);
    //     }
    //     if(us.size()==1) return true;
    //     int n=us.size();
    //     return n/2<=k;
    // }
};