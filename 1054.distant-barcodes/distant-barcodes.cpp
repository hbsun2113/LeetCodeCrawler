class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> ww;
        for(const auto &b:barcodes) ww[b]++;
        
        vector<pair<int,int>> um;  // 个数：索引
        for(const auto &w:ww){
            if(w.second!=0){
                um.push_back({w.second,w.first});
            }
        } 
        
        auto cmp=[](pair<int,int> &a, pair<int,int> &b){
            return a.first<b.first;
        };
        sort(um.begin(),um.end(),cmp);
        
        for(const auto &u:um){
            cout<<u.second<<" "<<u.first<<endl;
        }
        
        
        // 按组处理每一个数，只要把它们隔一个空处理就好
        vector<int> res(barcodes.size());
        int j=um.size()-1;
        for(int i=0;i<res.size();i+=2){
            if(um[j].first!=0){
                res[i]=um[j].second;
                um[j].first--;
            }
            else{
                i-=2;
                j--;
            }
        }
        
        for(int i=1;i<res.size();i+=2){
            if(um[j].first!=0){
                res[i]=um[j].second;
                um[j].first--;
            }
            else{
                i-=2;
                j--;
            } 
        }
        
        return res;
    }
};