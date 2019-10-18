class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp=[](vector<int> &a, vector<int> &b){
            return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        };
 
        priority_queue<vector<int>,vector<vector<int>>, decltype(cmp)> pq(cmp);
        for(int i=0;i<points.size();i++){
            pq.push(points[i]);
            if(pq.size()>K) pq.pop();
        }
        
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};