class Solution {
public:
    // https://leetcode.com/problems/max-consecutive-ones-iii/discuss/247564/JavaC++Python-Sliding-Window
    // Suggested by @migeater, we don't need to reduce the the size of sliding window, as we want to find the maximum window.
    int longestOnes(vector<int>& A, int K) {
        int i,j;
        for(i=0,j=0;j<A.size();++j){
            if(A[j]==0) K--;
            if(K<0){
                if(A[i]==0) K++;
                i++;
            }
            cout<<j-i+1<<endl;
        }
        return j-i;
    }
    
    
    // 做麻烦了
    int longestOnes1(vector<int>& A, int K) {
        if(A.size()==0) return 0;
        int res=0;
        vector<int> vec(2,0);
        for(int i=0,j=0;j<A.size();j++){
            vec[A[j]]++;
            while(vec[0]>K){
                vec[A[i++]]--;
            }
            // for(int k=i;k<=j;k++) cout<<A[k]<<" ";
            // cout<<":"<<j-i+1<<" "<<K+vec[1]-vec[0]<<endl;
            res=max(res,j-i+1);
        }
        return res;
    }
    
    
};