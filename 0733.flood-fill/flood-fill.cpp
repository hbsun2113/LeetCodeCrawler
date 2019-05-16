class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        int oriColor=image[sr][sc];
        if(oriColor==newColor) return image;
        queue<pair<int,int>> q;
        q.emplace(sr,sc);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            image[node.first][node.second]=newColor;
            for(int k=0;k<4;k++){
                int xx=node.first+dx[k];
                int yy=node.second+dy[k];
                // cout<<xx<<" "<<yy<<endl;
                if(xx>=0 && xx<image.size() && yy>=0 && yy<image[0].size() && image[xx][yy]==oriColor)
                    q.emplace(xx,yy);
            }
        }
        return image;
    }
};