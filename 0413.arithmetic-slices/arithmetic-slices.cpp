class Solution {
/*
0 1 2 3
*/
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        vector<int> result(A.size(),0);
        int index=0;
        while(index<=A.size()-1-2){
            int d=A[index+1]-A[index];
            int x=index+2;
            while(A[x]-A[x-1]==d) x++;
            x--;
            if(x-index>=2){
                result[index]=x;
                index=x+1;
                cout<<"success_x="<<x<<endl;
            }
            else{
                cout<<"fail_x="<<x<<endl;
                index++;
            }
        }
        int count=0;
        for(int i=0;i<result.size();i++){
            int len=result[i]-i+1;
            if(len>2){
               count+=(len - 1) * (len - 2) * 0.5;
            }
        }
        return count;
    }
};