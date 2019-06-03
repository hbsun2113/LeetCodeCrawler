class Solution {
public:
    // 二刷
    // 教训：bfs的思路应该是：
    // 最开始的时候 一下子就把种子全部收进来，不可以先放一个种子，对它进行bfs。然后再放其他种子
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
        int row=m.size();
        if(row==0) return m;
        int col=m[0].size();
        vector<vector<int>> res(row,vector<int>(col,INT_MAX));
        
        queue<pair<int,int>>  q;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(m[i][j]!=0) continue;
                res[i][j]=0;
                q.push({i,j});
            }
        }
            
        while(!q.empty()){
            int size=q.size();
            for(int s=0;s<size;s++){
                auto t=q.front();
                q.pop();
                int x=t.first,y=t.second;
                for(int k=0;k<4;k++){
                    int xx=x+dx[k];
                    int yy=y+dy[k];
                    if(xx<0 || xx>=row || yy<0 || yy>=col || m[xx][yy]==0 || res[xx][yy]<=res[x][y]+1) continue;
                    res[xx][yy]=res[x][y]+1;
                    q.push({xx,yy});
                }
            }
        }
                
        return res;
    }
};

