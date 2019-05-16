class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0) return 0;
        int result=0;
        for(int i=1;i<timeSeries.size();i++){
            int interval=timeSeries[i]-timeSeries[i-1];
            result+=min(interval,duration);
        }
        return result+duration;
    }
};