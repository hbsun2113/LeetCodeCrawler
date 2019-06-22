class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> dx={0,0,1,-1,1,1,-1,-1};
        vector<int> dy={1,-1,0,0,1,-1,1,-1};
        queue<vector<int>> q;
        int row=grid.size();
        if(row==0) return -1;
        int col=grid[0].size();
        if(grid[0][0]==1 || grid[row-1][col-1]==1) return -1;
        q.push({0,0,1});
        grid[0][0]=1;
        int l=1;
        int x,y;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            x=t[0],y=t[1],l=t[2];
            if(x==row-1 && y==col-1) break;
            //grid[x][y]=1;
            
            for(int k=0;k<8;k++){
                int xx=x+dx[k];
                int yy=y+dy[k];
                if(xx<0 || xx>=row || yy<0 || yy>=col || grid[xx][yy]==1) continue;
                
                q.push({xx,yy,l+1});
                grid[xx][yy]=1; // 入队后要立即改变状态，否则会TLE。原因：相比于在第20行改变状态，可以节省时间。因为如果其他的点也发现了这个点，由于它的状态没有改变，就还会将它入队(重复入队)。而只有该点第一次入队是最优解。
            }
        }
        
        if(x==row-1 && y==col-1) return l;
        else return -1;
        
    }
};