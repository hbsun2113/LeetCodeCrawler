class Solution {
public:
    //https://leetcode.com/problems/2-keys-keyboard/discuss/105899/Java-DP-Solution
    int minSteps1(int n) {
        vector<int> result(n+1,0);
        for(int i=2;i<=n;i++){
            result[i]=i;
            for(int j=i-1;j>=2;j--){
                if(i%j==0){
                    result[i]=min(result[i],result[j]+i/j);
                }
            }
        }
        return result[n];
    }
    
    
    
    int minSteps(int n) {
        if(n==1) return 0;
        int result=n;
        for(int i=n-1;i>=2;i--){
            if(n%i==0){
                result=min(result,minSteps(n/i)+i);
            }
        }
        return result;
    }
    
    // 更高效一点的做法：
    // https://www.acwing.com/solution/LeetCode/content/502/
};