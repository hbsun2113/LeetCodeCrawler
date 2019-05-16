class Solution {
public:
    //就是将二维的01背包问题转化成三维01背包问题，没有什么新意。最需要注意的就是数组索引了，其他感觉都问题不大。
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> tmp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1)));
        for(int i=1;i<=strs.size();i++){
            for(int j=0;j<=m;j++){
                for(int h=0;h<=n;h++){
                    auto pp=helper(strs[i-1]);
                    int x=pp.first,y=pp.second;
                    tmp[i][j][h]=tmp[i-1][j][h];
                    if(j>=x && h>=y)
                        tmp[i][j][h]=max(tmp[i][j][h],tmp[i-1][j-x][h-y]+1);
                    //cout<<tmp[i][j][h]<<endl;
                }
            }
        }
        return tmp[strs.size()][m][n];
    }
    
    pair<int,int> helper(string s){
        int one=0,zero=0;
        for(const auto &c:s){
            if(c=='0') zero++;
            else one++;
        }
        return make_pair(zero,one);
    }
};