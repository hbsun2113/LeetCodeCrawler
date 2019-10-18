class Solution {
public:
    // ??????????????????????
    // ??????????BFS????????????DFS??????????grandyang?????
    // ????????
    int row,col;
    vector<int> dx={0,1,-1,0}; 
    vector<int> dy={1,0,0,-1};
    int a,b;
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        row=maze.size();
        if(row==0) return false;
        col=maze[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        a=destination[0],b=destination[1];
        
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        vis[start[0]][start[1]]=true;
        
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            if(n.first==a && n.second==b) return true;
            for(int k=0;k<4;k++){
                int x=n.first; // 1:x?y??for??????
                int y=n.second;
                int xx=x+dx[k];
                int yy=y+dy[k];
                while(xx>=0 && xx<row && yy>=0 && yy<col && maze[xx][yy]==0 && maze[xx][yy]==false){
                    x=xx,y=yy;
                    xx=x+dx[k],yy=y+dy[k];
                }
                if(x<0 || x>=row || y<0 || y>=col || maze[x][y]==1 || vis[x][y]==true) continue;//2:????????xy????????
                vis[x][y]=true;
                q.push({x,y});
            }
        }
        
        return false;
    }
};