class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n=calories.size();
        vector<long long> presum(n+1,0);
        for(int i=1;i<=n;i++)
            presum[i]=presum[i-1]+calories[i-1];
        int res=0;
        for(int i=k;i<=n;i++){
            if(i-k<0) continue;
            if(presum[i]-presum[i-k]>upper) res++;
            else if(presum[i]-presum[i-k]<lower) res--;
        }
        return res;
    }
};