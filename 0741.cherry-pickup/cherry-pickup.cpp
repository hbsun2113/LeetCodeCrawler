class Solution {
public:
    // https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-741-cherry-pickup/
    // ?????????????dp???https://www.cnblogs.com/grandyang/p/8215787.html???
    // ???????????????????????????????????????????
    // ?????????x1+y1==x2+y2?
    vector<vector<int>> grid;
    vector<vector<vector<int>>> m;
    int cherryPickup(vector<vector<int>>& g) {
        grid=g;
        if(g.empty()) return 0;
        int row=g.size();
        int col=g[0].size();
        m.resize(row,vector<vector<int>>(col,vector<int>(row,INT_MIN)));
        return max(0,dfs(row-1,col-1,row-1));
    }
    
    // -1?????????????;INT_MIN???????
    int dfs(int x1, int y1, int x2){
        const int y2=x1+y1-x2;
        if(x1<0 || y1<0 || x2<0 || y2<0 || grid[x1][y1]<0 || grid[x2][y2]<0) return -1;
        if(m[x1][y1][x2]!=INT_MIN) return m[x1][y1][x2];  // ????????
        if(x1==0 && y1==0) return grid[0][0]; 
        int res=max(max(dfs(x1,y1-1,x2-1),dfs(x1-1,y1,x2-1)),max(dfs(x1-1,y1,x2),dfs(x1,y1-1,x2)));
        if(res<0) return m[x1][y1][x2]=-1;
        res+=grid[x1][y1]+grid[x2][y2];
        if(x1==x2) res-=grid[x2][y2]; // ???????????????
        return m[x1][y1][x2]=res;
    }
};