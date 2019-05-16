class Solution {
public:
    //二刷
    int res;
    vector<bool> flag; //flag[i]标明数字i是否已经被使用。
    int N;
    int countArrangement(int NN) {
        N=NN;
        res=0;
        flag.resize(N+1,true);
        dfs(1);
        return res;
    }
    
    void dfs(int index){
        if(index>N){
            res++;
            return ;
        }
        for(int i=1;i<=N;i++){
            if(flag[i] && (i%index==0 || index%i==0)){
                flag[i]=false;
                dfs(index+1);
                flag[i]=true;
            }
        }
        
    }
    
    
    
    
    
    //错误答案，列举不全。
    int countArrangement1(int N) {
        vector<int> vec(N+1);
        vec[1]=1;
        for(int i=2;i<=N;i++){
            vec[i]=vec[i-1];
            for(int j=1;j<i;j++){
                if(judge(j,i) && judge(i,j)) vec[i]+=vec[j];
            }
        }
        return vec[N];
    }
    
    
    bool judge(int index, int value){
        // cout<<index<<" "<<value<<" "<<index%value<<" "<<value%index<<endl;
        return (index%value==0) || (value%index==0);
    }
};