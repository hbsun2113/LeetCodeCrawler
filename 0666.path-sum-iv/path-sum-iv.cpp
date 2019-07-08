#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    // 自己做的
    int res=0;
    int pathSum(vector<int>& nums) {
        vector<vector<int>> vec(5,vector<int>(9,-1));
        for(auto &n:nums){
            int V=n%10;
            n/=10;
            int P=n%10;
            n/=10;
            int D=n%10;
            vec[D][P]=V;
        }
        
        dfs(1,1,vec,0);
        
        return res;
    }
    
    
    void dfs(int i, int j, vector<vector<int>> &vec, int cur){
            if(i==4 && vec[i][j]!=-1){ // 特判叶子节点
                res+=cur+vec[i][j];
                return ;
            }
            if(i==4) return ;

            int val=vec[i][j];
            if(val==-1) return; 
            auto l=vec[i+1][j*2-1];
            auto r=vec[i+1][j*2];
            if(l>=0 || r>=0){ // 只要有一个儿子就是非叶节点
                dfs(i+1,j*2-1,vec,cur+val);
                dfs(i+1,j*2,vec,cur+val);
            }
            else{
                res+=cur+vec[i][j];  // 特判叶子节点
            }
            
            return ;
    }
};