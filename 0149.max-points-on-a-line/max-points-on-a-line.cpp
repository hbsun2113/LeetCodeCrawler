/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    // 二刷，做得不是很好
    int maxPoints2(vector<Point>& points) {
        auto cmp=[](Point &a, Point& b){
            if(a.x<b.x) return true;
            else if(a.x==b.x && a.y<b.y) return true;
            return false;
        };
        //sort(points.begin(),points.end(),cmp);
        if(points.size()==0) return 0;
        int res=1;
        for(int i=0;i<points.size();i++){
            auto &p=points[i];
            int duplicate=1;
            unordered_map<long double,int> um;
            for(int j=i+1;j<points.size();j++){
                int x=p.x, y=p.y;
                int a=points[j].x, b=points[j].y;
                if(a==x && b==y){
                    duplicate++;
                    continue;
                }
                if(a==x){
                    um[INT_MAX]++;
                    continue;
                }
                long double k=(long double)(b-y)/(long double)(a-x);
                um[k]+=1;
            }
            for(const auto &u:um){
                res=max(res,duplicate+u.second);
            }
            res=max(res,duplicate);
        }
        return res;
    }
    
    
    int maxPoints(vector<Point>& points) {
        if(points.size()==0) return 0;
        int result=1;
        for(int i=0;i<points.size();i++){
            int x=points[i].x,y=points[i].y;
            unordered_map<long double,int> um;
            int same=1; //记录重合的点的个数
            for(int j=i+1;j<points.size();j++){
                int jx=points[j].x,jy=points[j].y;
                if(x==jx && y!=jy) um[INT_MAX]++;
                else if(x==jx && y==jy) same++;
                else{
                    long double k=(long double)(jy-y)/(jx-x);
                    um[k]++;
                }    
            }
            for(const auto &m:um){
                result=max(result,m.second+same);
            }
            result=max(result,same);
            
        }
        return result;
    }
};