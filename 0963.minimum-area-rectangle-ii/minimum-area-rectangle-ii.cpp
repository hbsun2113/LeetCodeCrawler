class Solution {
public:
    // https://leetcode.com/problems/minimum-area-rectangle-ii/discuss/208361/JAVA-O(n2)-using-Map
    // ?????????????????????????
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<string,vector<pair<int,int>>> um;
        int n=points.size();
        if(n<4) return 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int len=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                double centerX=double(points[i][0]+points[j][0])/2.000; // ????????????double???
                double centerY=double(points[i][1]+points[j][1])/2.000;
                
                string key=to_string(len)+":"+to_string(centerX)+","+to_string(centerY);
                um[key].push_back({i,j});
            }
        }
        
        double res=INT_MAX;
        
        for(auto &n:um){
            auto &list=n.second;
            if(list.size()==1) continue; 
            for(int i=0;i<list.size();i++){
                for(int j=i+1;j<list.size();j++){
                    auto v1=list[i].first;
                    auto v2=list[i].second;
                    auto v3=list[j].first;
                    auto v4=list[j].second;
                    double m=sqrt((points[v1][0]-points[v3][0])*(points[v1][0]-points[v3][0])+(points[v1][1]-points[v3][1])*(points[v1][1]-points[v3][1]));
                    double n=sqrt((points[v2][0]-points[v3][0])*(points[v2][0]-points[v3][0])+(points[v2][1]-points[v3][1])*(points[v2][1]-points[v3][1]));
                    // cout<<m<<" "<<n<<":"<<v1<<" "<<v2<<" "<<v3<<" "<<v4<<endl;
                    res=min(res,m*n);
                }
            }
        }
        
        if(res==INT_MAX) return 0;
        else return res;
    }
};