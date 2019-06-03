class Solution {
public:
    int i=0;
    int used=0;
    unordered_map<int,int> um;
    bool canIWin(int h, int d) {
        if(h>d) return true;
        if((1+h)*h/2<d) return false;
        return dfs(0,h,d,0);
    }
    
    bool dfs(int cur, int h, int d, int used){
        if(um.find(used)!=um.end()) return um[used];
        for(int i=1;i<=h;i++){
            int flag=1<<i;
            if((used&flag)!=0) continue;
            if(i+cur>=d || !dfs(cur+i,h,d,used|flag)){
                um[used]=true;
                return true;
            } 
        }
        um[used]=false;
        return false;
    }
};