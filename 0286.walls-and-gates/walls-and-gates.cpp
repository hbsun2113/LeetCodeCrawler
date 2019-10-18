class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) return ;
        queue<pair<int,int>> q;
        int row=rooms.size(),col=rooms[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rooms[i][j]==0) q.push({i,j});
            }
        }
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            auto x=n.first;
            auto y=n.second;
            for(int k=0;k<4;k++){
                int xx=x+dx[k];
                int yy=y+dy[k];
                if(xx<0 || xx>=row || yy<0 || yy>=col || rooms[xx][yy]==-1 || rooms[xx][yy]<rooms[x][y]+1) continue;
                rooms[xx][yy]=rooms[x][y]+1;
                q.push({xx,yy});
            }
        }
    }
};