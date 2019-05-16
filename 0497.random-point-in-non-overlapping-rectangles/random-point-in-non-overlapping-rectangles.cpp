class Solution {
public:
    Solution(vector<vector<int>> rects) {
        this->rects=rects;
        sum=0;
        for(int i=0;i<rects.size();i++){
            auto const &rect=rects[i];
            int area=(rect[2]-rect[0]+1)*(rect[3]-rect[1]+1);
            sum+=area;
            m[sum]=i;
        }
    }
    
    vector<int> pick() {
        auto it=m.lower_bound(rand()%sum+1);
        int index=it->second;
        auto rec=rects[index];
        vector<int> result;
        int x=rec[0]+rand()%(rec[2]-rec[0]+1);
        int y=rec[1]+rand()%(rec[3]-rec[1]+1);
        result.push_back(x);
        result.push_back(y);
        return result;
        
    }
    
    
    
    map<int,int> m;
    vector<vector<int>> rects;
    int sum;
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */