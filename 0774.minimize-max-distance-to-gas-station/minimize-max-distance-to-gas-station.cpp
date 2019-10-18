class Solution {
public:
    // https://leetcode.com/problems/minimize-max-distance-to-gas-station/discuss/113633/C++JavaPython-Binary-Search
    double minmaxGasDist(vector<int>& stations, int K) {
        if(stations.empty()) return 0;
        double l=0,r=stations.back()-stations[0];  // ???????????D
        while(l+1e-6<r){ // ?????1e-6
            double mid=(l+r)/2.00;
            int cnt=0;
            for(int i=0;i+1<stations.size();i++){
                cnt+=ceil((stations[i+1]-stations[i])/mid)-1; // ???[1,6],??mid=2
            }
            if(cnt<=K) r=mid; // ?????????????:cnt==K??????????????????(smallest)?mid
            else l=mid;
        }
        return r;
    }
};