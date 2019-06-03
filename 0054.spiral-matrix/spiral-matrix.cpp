class Solution {
public:
    // 做得不是很流畅
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        row=matrix.size();
        if(row==0) return res;
        col=matrix[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        
        int k=0;
        int x=0,y=0;
        
        while(res.size()!=row*col){
            res.push_back(matrix[x][y]);
            if(res.size()==row*col) break;
            vis[x][y]=true;
            while(x+dx[k]<0 || x+dx[k]>=row || y+dy[k]<0 || y+dy[k]>=col || vis[x+dx[k]][y+dy[k]]){
                k++;
                k%=4;
            }
            x=x+dx[k];
            y=y+dy[k];
            
        }
        return res;
    }
    
    
    // 三刷，自己做出来了
    // 更简洁的做法,没有while，只有if：https://www.acwing.com/solution/acwing/content/748/
    int row, col;
    vector<vector<bool>> vis;
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};
    vector<int> res;
    int k=0;
    vector<int> spiralOrder3(vector<vector<int> > matrix) {
        
        row=matrix.size();
        if(row==0) return res;
        col=matrix[0].size();
        if(col==0) return res;
        vis.resize(row,vector<bool>(col,false));
        
        dfs(matrix,0,0);
        
        return res;
        
    }
    
    void dfs(vector<vector<int>> matrix, int x, int y){
        res.push_back(matrix[x][y]);
        cout<<matrix[x][y]<<endl;
        vis[x][y]=true;
        
        int xx=x+dx[k];
        int yy=y+dy[k];
        int count=0;
        while(xx<0 || xx>=row || yy<0 || yy>=col || vis[xx][yy]){
            count++;
            if(count>=4) return;
            k++;
            k%=4;
            xx=x+dx[k];
            yy=y+dy[k];
            // cout<<matrix[x][y]<<" "<<xx<<" "<<yy<<" "<<k<<endl;
        }
        
        dfs(matrix,xx,yy);
        
    }
    
    
    // 二刷，之前写得感觉太麻烦了，看看别人的代码：
    // https://www.acwing.com/solution/LeetCode/content/134/
    // 最难处理的是拐点，但是在每个拐点其实再往前就只有一个可行解，所以枚举即可
    // 方向问题其实也很难处理，这里用了模的思想，并且注意我们的方向是有顺序的
    // 
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        vector<int> vec;
        int row=matrix.size();
        if(row==0) return vec;
        int col=matrix[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        vector<int> dx={0,1,0,-1}; // 与其他题不同，这里dx和dy是有顺序的。
        vector<int> dy={1,0,-1,0};
        int x=0,y=0,dir=0;
        bool flag;
        while(1){
            vec.push_back(matrix[x][y]);
            vis[x][y]=true;
            flag=false;
            for(int k=0;k<4;k++){
                int xx=x+dx[(k+dir)%4];
                int yy=y+dy[(k+dir)%4];
                
                if(xx<0 || xx>=row || yy<0 || yy>=col || vis[xx][yy]) continue;
                
                x=xx;
                y=yy;
                dir=(k+dir)%4;
                flag=true;
                break;
            }
            if(!flag) break;
        }
        return vec;
        
    }
    
    
    
    
    
};