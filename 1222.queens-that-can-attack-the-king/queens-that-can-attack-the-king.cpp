class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int row=king[0],col=king[1];
        unordered_map<int,vector<vector<int>>> um;
        for(const auto &q:queens){
            if(q[0]==row && q[1]<col) um[0].push_back({q[0],q[1]});
            else if(q[0]==row && q[1]>col) um[1].push_back({q[0],q[1]});
            else if(q[1]==col && q[0]<row) um[2].push_back({q[0],q[1]});
            else if(q[1]==col && q[0]>row) um[3].push_back({q[0],q[1]});
            else if(row-col==q[0]-q[1] && row>q[0]) um[4].push_back({q[0],q[1]});
            else if(row-col==q[0]-q[1] && row<q[0]) um[5].push_back({q[0],q[1]});
            else if(row+col==q[0]+q[1] && row>q[0]) um[6].push_back({q[0],q[1]});
            else if(row+col==q[0]+q[1] && row<q[0]) um[7].push_back({q[0],q[1]});
        }
        
        vector<vector<int>> res;
        auto cmp=[row,col](vector<int> &a, vector<int> &b){
            return ((a[0]-row)*(a[0]-row)+(a[1]-col)*(a[1]-col))<((b[0]-row)*(b[0]-row)+(b[1]-col)*(b[1]-col));
        };
        
        for(const auto &n:um){
            auto l=n.second;
            sort(l.begin(),l.end(),cmp);
            res.push_back(l[0]);
        }
        
        return res;
    }
};