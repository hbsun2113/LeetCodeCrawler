class Solution {
public:
    //这道题目做得很烂 以后请不要看别人答案再做 这样copy怎么能提高？？！！
    string getPermutation(int n, int k) {
        vector<int> now;
        for(int i=1;i<=n;i++) now.push_back(i);
        for(int i=1;i<k;i++) permutation(now);
        return put(now);
        
    }
    
    
    void permutation(vector<int>& now){
        int i=now.size()-2;
        while(i>0 && now[i]>=now[i+1]) i--;
        int j=now.size()-1;
        while(now[j] <= now[i]) j--; 
        swap(i,j,now);
        reverse(i+1,now.size()-1,now);
    }
    
    string put(vector<int> & result){
        string tmp="";
        for(auto &r:result){
            tmp+=to_string(r);
            // tmp+=r;注意 这样的写法是错误的！！！
            
        }
        return tmp;
    }
    
    void swap(int i,int j,vector<int>& now){
        int tmp=now[i];
        now[i]=now[j];
        now[j]=tmp;
    }
    
    void reverse(int i,int j,vector<int> & now){
        while(i<j) swap(i++,j--,now);
    }
};