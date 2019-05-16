class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int limit=INT_MIN;
        for(const auto &w:weights)
            limit=max(limit,w);
        for(int w=limit;w<=25000010;w++){
            int index=0;
            int sum=0;
            int day=0;
            while(index<weights.size()){
                if(sum+weights[index]<=w){
                    sum+=weights[index];
                    index++;
                }
                else{
                    day++;
                    sum=0;
                }
            }
            if(day+1<=D) return w;
        }
        return 0;
    }
};