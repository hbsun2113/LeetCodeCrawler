class Solution {
public:
    // 二刷
    // 先按照first进行排序，但如果first相等，我们要把second大的排在前面，这样就避免了后续我们处理second时认为相等的可以包含。
    // 然后按照second找到最长递增序列的长度就可以了，注意是可以不连续的。https://leetcode.com/problems/longest-increasing-subsequence/description/
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size()==0) return 0;
        auto cmp=[](pair<int, int> a, pair<int, int> b){
            if(a.first<b.first) return true;
            if(a.first>b.first) return false;
            return a.second>b.second;
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> vec(envelopes.size());
        int size=0;
        for(const auto &e:envelopes){
            int l=-1,r=size;
            while(l+1!=r){
                int mid=l+(r-l)/2;
                if(vec[mid]<e.second) l=mid;
                else r=mid;
            }
            vec[r]=e.second;
            if(r==size) size++;
        }
        return size;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int maxEnvelopes1(vector<pair<int, int>>& envelopes) {
        if(envelopes.size()<=1) return envelopes.size();
        auto cmp=[](auto a, auto b){
            if(a.first<b.first) return true;
            if(a.first>b.first) return false;
            return a.second>b.second; //https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation
        };
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> vec(envelopes.size(),0);
        int res=INT_MIN;
        vec[0]=1;
        for(int i=1;i<vec.size();i++){
            for(int j=0;j<i;j++)
            if(envelopes[i].second>envelopes[j].second)
                vec[i]=max(vec[i],vec[j]);
            vec[i]+=1;
            res=max(res,vec[i]);
        }
        return res;
    }
};