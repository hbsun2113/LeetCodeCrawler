class Solution {
public:
    //参考了http://www.cnblogs.com/grandyang/p/4534586.html
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result,tmp;
        multiset<int> m;
        for(const auto& b:buildings){
            tmp.push_back(pair<int,int>(b[0],-b[2]));
            tmp.push_back(pair<int,int>(b[1],b[2]));
        }
        sort(tmp.begin(),tmp.end());
        m.emplace(0); //以备不时之需。
        int current;
        int pre(-10);
        for(const auto &t:tmp){
            cout<<m.count(0)<<endl;
            if(t.second<0) m.emplace(-t.second);
            else{
                //cout<<t.second<<endl;
                m.erase(m.find(t.second));
            }
            current=*m.rbegin();
            if(current!=pre){
                result.push_back(pair<int,int>(t.first,current));
                pre=current;
            }
        }
        
        
        
        return result;;
    }
};