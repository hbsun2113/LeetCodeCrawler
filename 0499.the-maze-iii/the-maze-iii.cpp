class Solution {
public:
    class Point{
    public:
        int x,y,c;
        string path;
        Point(int _x, int _y, int _c, string _s=""):x(_x),y(_y),c(_c),path(_s){};
    };
    
    int row,col;
    vector<int> dx={0,1,-1,0}; 
    vector<int> dy={1,0,0,-1};
    vector<string> dc={"r","d","u","l"};
    int a,b;
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<string> res;
        row=maze.size();
        if(row==0) return "impossible";
        col=maze[0].size();
        vector<vector<int>> vis(row,vector<int>(col,INT_MAX));
        a=destination[0],b=destination[1];
        
        queue<Point> q;
        q.push(Point(start[0],start[1],1));
        vis[start[0]][start[1]]=1;
        
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x=n.x;
                int y=n.y;
                int c=n.c;
                int xx=x+dx[k];
                int yy=y+dy[k];
                while(xx>=0 && xx<row && yy>=0 && yy<col && maze[xx][yy]==0 && maze[xx][yy]==false){
                    x=xx,y=yy;
                    c++;
                    if(x==a && y==b && c<=vis[a][b]){
                        cout<<n.path+dc[k]<<endl;
                        if(c<vis[a][b]) res.clear();
                        vis[a][b]=c;
                        res.push_back(n.path+dc[k]);
                        continue;
                    }
                    xx=x+dx[k],yy=y+dy[k];
                }
                // cout<<n.x<<" "<<n.y<<" "<<n.c<<" "<<x<<" "<<y<<" "<<c<<endl;
                if(x==a && y==b) continue;
                if(x==n.x && y==n.y) continue; // ??????????????????????
                if(vis[x][y]<c) continue; // ??????????????????????
                
                vis[x][y]=c;
                q.push(Point(x,y,c,n.path+dc[k]));
            }
        }
    
        if(res.size()==0) return "impossible";
        sort(res.begin(),res.end());
        return res[0];
    }
};