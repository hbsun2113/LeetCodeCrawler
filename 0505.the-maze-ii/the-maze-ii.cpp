class Solution {
public:
    // ??490. The Maze ??:
    // 1. vis?????????????
    // 2. queue???????
    int row,col;
    vector<int> dx={0,1,-1,0}; 
    vector<int> dy={1,0,0,-1};
    int a,b;
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        row=maze.size();
        if(row==0) return false;
        col=maze[0].size();
        vector<vector<int>> vis(row,vector<int>(col,INT_MAX));
        a=destination[0],b=destination[1];
        
        queue<vector<int>> q;
        q.push({start[0],start[1],1});
        vis[start[0]][start[1]]=true;
        
        int res=INT_MAX;
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            if(n[0]==a && n[1]==b){
                res=min(res,n[2]-1);
                continue;
            }
            for(int k=0;k<4;k++){
                int x=n[0];
                int y=n[1];
                int c=n[2];
                int xx=x+dx[k];
                int yy=y+dy[k];
                while(xx>=0 && xx<row && yy>=0 && yy<col && maze[xx][yy]==0 && maze[xx][yy]==false){
                    x=xx,y=yy;
                    c++;
                    xx=x+dx[k],yy=y+dy[k];
                }
                if(vis[x][y]<=c) continue;
                // cout<<n[0]<<" "<<n[1]<<" "<<n[2]<<" "<<x<<" "<<y<<" "<<c<<endl;
                vis[x][y]=c;
                q.push({x,y,c});
            }
        }
        if(res!=INT_MAX) return res;
        else return -1;
    }
};