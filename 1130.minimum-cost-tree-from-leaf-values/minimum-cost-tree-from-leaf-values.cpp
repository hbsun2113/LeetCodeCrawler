class Solution {
public:
    // https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/JavaC++Python-One-Pass-O(N)-Time-and-Space
    int mctFromLeafValues(vector<int>& a1) {
        vector<int> s;
        s.push_back(INT_MAX);
        int res=0;
        for(const auto &n:a1){
            while(!s.empty() && n>s.back()){ 
                int a=s.back();
                s.pop_back();
                res+=a*min(s.back(),n);
            }
            s.push_back(n);
        }
        
        // ?????
        for(int i=2;i<s.size();i++){
            res+=s[i]*s[i-1];
        }
        
        return res;
    }
    
    
    // ?????
    //neal_wu?????????????k?????????????????????????
    //????[l,r)???????????????????memorisize??????
    vector<vector<int>> dp;
    vector<int> arr;
    int mctFromLeafValues1(vector<int>& a1) {
        arr=a1;
        dp.resize(45,vector<int>(45,INT_MAX));
        int n=a1.size();
        dfs(0,n);
        return dp[0][n];
    }
    
    int dfs(int l, int r){
        if(r-l<=1) return 0; // ???????r==l+1???????
        if(dp[l][r]!=INT_MAX) return dp[l][r];
        for(int k=l+1;k<r;k++){
            int left=0,right=0;
            for(int j=l;j<k;j++) left=max(left,arr[j]);
            for(int j=k;j<r;j++) right=max(right,arr[j]);
            dp[l][r]=min(dp[l][r], dfs(l,k)+dfs(k,r)+left*right);
        }
        return dp[l][r];
    }
};