class Solution {
public:
    // 希望自己能在没有任何提示下做出来
    int leastBricks3(vector<vector<int>>& wall) {
        return 0;
       
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // 三刷 
    int leastBricks(vector<vector<int>>& wall) {
        int row=wall.size();
        int maxv=INT_MIN;
        unordered_map<int,int> um;
        int filter=accumulate(wall[0].begin(),wall[0].end(),0);
        for(const auto &w:wall){
            int sum=0;
            for(const auto &i:w){
                sum+=i;
                if(sum!=filter)
                    um[sum]++;
                maxv=max(maxv,um[sum]);
            }
        }
        return row-maxv;
    }
    
    
    //二刷自己做的，只要想到用map做，这道题就不难了，关键是要想到。
    int leastBricks2(vector<vector<int>>& wall) {
        unordered_map<int,int> um;
        int result=INT_MIN;
        int tmp=accumulate(wall[0].begin(),wall[0].end(),0);
        for(const auto &line:wall){
            int w=0;
            for(const auto &width:line){
                w+=width;
                um[w]++;
                if(w!=tmp) result=max(result,um[w]);
            }
        }
        if(result==INT_MIN) result=0;
        return wall.size()-result;
    }
};