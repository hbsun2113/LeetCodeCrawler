class Solution {
public:
    vector<int> parent;
    int find(int i){
        while(parent[i]!=i){
            parent[i]=parent[parent[i]];
            i=parent[i];
        }
        return i;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(const auto &v:pairs){
            int a=find(v[0]);
            int b=find(v[1]);
            if(a!=b){
                parent[a]=min(a,b);
                parent[b]=min(a,b);
            } 
        }
        
        unordered_map<int,multiset<char>> um;
        for(int i=0;i<n;i++){
            parent[i]=find(parent[i]);
            // cout<<i<<" "<<parent[i]<<endl;
            um[parent[i]].insert(s[i]);
        }
        
        for(int i=0;i<n;i++){
            s[i]=*(um[parent[i]].begin());
            um[parent[i]].erase(um[parent[i]].find(s[i]));
        }
        
        return s;
    }
};