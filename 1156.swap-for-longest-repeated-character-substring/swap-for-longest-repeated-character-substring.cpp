class Solution {
public:
    int maxRepOpt1(string text) {
        if(text.size()<=1) return text.size();
        int n=text.size();
        unordered_map<char,vector<pair<int,int>>> um;
        char &c=text[0];
        int start=0;
        int i=0;
        while(i<n){
            while(i<n && text[i]==c) i++;
            um[c].push_back({start,i-1});
            start=i;
            c=text[i];
        }
        
        int res=1;
        for(auto [u,v]:um){
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                if(i+1<v.size() && v[i].second==v[i+1].first-2){
                    int len=v[i].second-v[i].first+1+v[i+1].second-v[i+1].first+1;
                    if(v.size()>2) res=max(res,len+1);
                    else res=max(res,len);
                }
                if(v.size()>1) res=max(res,v[i].second-v[i].first+1+1);
                else res=max(res,v[i].second-v[i].first+1);
            }
        }
        
        return res;
    }
};