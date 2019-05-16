class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int x=grid.size();
        int y=grid[0].size();
        vector<int> row;
        for(int i=0;i<grid.size();i++){
            row.emplace_back(maxvalue(grid[i]));
        }
        // for(const auto &r:row) cout<<r<<" ";
        // cout<<endl;
        vector<int> col;
        for(int j=0;j<y;j++){
            vector<int> tmp;
            for(int i=0;i<x;i++) tmp.push_back(grid[i][j]);
            col.emplace_back(maxvalue(tmp));
        }
        // for(const auto &c:col) cout<<c<<" ";
        // cout<<endl;
        int result=0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(grid[i][j]!=row[i] && grid[i][j]!=col[j]){
                    result+=(min(row[i],col[j])-grid[i][j]);
                    grid[i][j]=min(row[i],col[j]);
                }
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        return result;
    }
    
    int maxvalue(vector<int> &v){
        int result=INT_MIN;
        for(const auto &c:v){
            result=max(result,c);
        }
        return result;
    }
};