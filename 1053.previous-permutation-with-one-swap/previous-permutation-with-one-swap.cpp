class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        for(int i=0;i<A.size();i++){
            bool flag=is_sorted(A.begin()+i+1,A.end());
            if(!flag) continue;
            
            int maxv=INT_MIN;
            int index;
            for(int j=i+1;j<A.size();j++){
                if(A[j]<A[i] && maxv<=A[j]){
                    maxv=A[j];
                    index=j;
                }
            } 
            
            
            if(maxv==INT_MIN) continue;
            
            swap(A[i],A[index]);
            break;
        }
        return A;
    }
};