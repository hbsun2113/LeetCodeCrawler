class Solution {
public:
    vector<bool> vec;
    bool divisorGame(int N) {
        vec.resize(1010,false);
        vec[0]=false;
        vec[1]=false;
        vec[2]=true;
        vec[3]=false;
        for(int i=4;i<=N;i++){
            for(int j=1;j<i;j++){
                if(i%j==0) vec[i]=vec[i] | !vec[i-j];
            }
        }
        return vec[N];
    }
    
};