class Solution {
public:
    // 比赛的时候想复杂了
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[0][0]-points[1][0])*(points[1][1]-points[2][1])!=(points[0][1]-points[1][1])*(points[1][0]-points[2][0]);
    }
    
    bool isBoomerang1(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        if((points[0][0]==points[1][0] && points[0][1]==points[1][1]) || (points[1][0]==points[2][0] && points[1][1]==points[2][1])) return false;
        if(points[0][0]==points[1][0] && points[2][0]==points[1][0]) return false;
        if(points[0][0]!=points[1][0] && points[2][0]==points[1][0]) return true;
        if(points[0][0]==points[1][0] && points[2][0]!=points[1][0]) return true;
        double k1=((points[0][1]-points[1][1]+0.000)/(points[0][0]-points[1][0]));
        double k2=((points[1][1]-points[2][1]+0.000)/(points[1][0]-points[2][0]));
        // cout<<k1<<" "<<k2<<endl;
        if(k1==k2) return false;
        return true;
    }
};