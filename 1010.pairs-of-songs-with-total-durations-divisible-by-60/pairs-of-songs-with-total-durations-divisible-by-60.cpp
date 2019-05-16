class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res=0;
        unordered_map<int,int> um; 
        int target;
        vector<int> tmp;
        for(int i=1;i*60<=1000;i++){
            tmp.push_back(i*60);
        }
        for(const auto t:time){
            for(const auto v:tmp){
                int target=v-t;
                if(um.find(target)!=um.end()) res+=um[target];
            }
            um[t]++;    
        }
            
        return res;
    }
};