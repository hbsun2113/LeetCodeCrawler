class Solution {
public:
    // 使用multi_map<int,int> 可以更快解题
    // https://leetcode.com/problems/largest-values-from-labels/discuss/312720/C++-Greedy
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        if(values.size()==0 || use_limit==0 || num_wanted==0) return 0;
        vector<pair<int,int>> vec;
        for(int i=0;i<values.size();i++){
            vec.push_back({values[i],labels[i]});
        }
        unordered_map<int,int> um;
        int ans=0;
        auto cmp=[](pair<int,int> &a, pair<int,int> &b){
          if(a.first!=b.first) return a.first>b.first;
          else return a.second>b.second;
        };
        sort(vec.begin(),vec.end(),cmp);
        int n=0;
        int i=0;
        while(n<num_wanted && i<vec.size()){
            if(um[vec[i].second]<use_limit){
                // cout<<vec[n].first<<" "<<vec[n].second<<endl;
                ans+=vec[i].first;
                um[vec[i].second]++;
                n++;
            }
            i++;
            
            
        }
        return ans;
    }
};