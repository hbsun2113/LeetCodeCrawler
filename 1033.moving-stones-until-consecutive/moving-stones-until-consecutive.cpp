class Solution {
public:
    int max_sum;
    int min_sum;
    vector<int> numMovesStones(int a, int b, int c) {
        max_sum=0;
        min_sum=0;
        vector<int> vec{a,b,c};
        sort(vec.begin(),vec.end());
        a=vec[0];
        b=vec[1];
        c=vec[2];
        max_helper(a,b,c);
        min_helper(a,b,c);
        return {min_sum,max_sum};   
    }
    
    void max_helper(int a, int b, int c){
        max_sum+=(b-a-1);
        max_sum+=(c-b-1);
    }
    
    void min_helper(int a, int b, int c){
        if(b-a==1 && c-b==1) min_sum=0;
        else if(b-a<3 || c-b<3) min_sum=1;
        else min_sum=2;
    }
};