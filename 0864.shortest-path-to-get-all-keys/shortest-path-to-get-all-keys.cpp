class Solution {
 public:
    // https://www.cnblogs.com/grandyang/p/11219780.html
    // ????????grandyang?????ponyai?????
  int shortestPathAllKeys(vector<string>& grid) {
    int row=grid.size();
    int col=grid[0].size();
    int keyCnt=0;
    queue<pair<int,int>> q;
    unordered_set<string> vis;
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        if(grid[i][j]=='@'){
          q.push({i*col+j,0});
          vis.insert(to_string(i*col+j)+"_0");
        }
        else if(grid[i][j]>='a' && grid[i][j]<='z') keyCnt++;
      }
    }

    int res=0;
    while(!q.empty()){
      for(int i=q.size()-1;i>=0;i--){
        auto x=q.front().first/col,y=q.front().first%col,keys=q.front().second;
        q.pop();
        if(keys ==( (1<<keyCnt)-1) ) return res;
        for(int k=0;k<4;k++){
          int xx=x+dx[k];
          int yy=y+dy[k];
          int key=keys;
          if(vis.find(to_string(xx*col+yy)+"_"+to_string(key))!=vis.end()) continue;  
          if(xx<0 || xx>=row || yy<0 || yy>=col || grid[xx][yy]=='#') continue;
          char c=grid[xx][yy];
          if(c>='A' && c<='Z') if( keys & (1<<(c-'A'))==0 ) continue; // ???grandyang??
          if (c >= 'A' && c <= 'F' && ((keys >> (c - 'A')) & 1) == 0) continue;
          if(c>='a' && c<='z') key |= (1<<(c-'a'));
          
          q.push({xx*col+yy,key});
          vis.insert(to_string(xx*col+yy)+"_"+to_string(key));
        }
      }
      res++;
    }
    return -1;
  }
};