class Solution {
public:
    //参加比赛的最后一道题目，没有做出来
    //https://blog.csdn.net/magicbean2/article/details/79831339
    //https://leetcode.com/problems/split-array-with-same-average/discuss/121140/DP-solution-in-C%2B%2B/233387
    /*
    因为A_sum/A_N==B_sum/B_N==C_sum/C_N(平均数相等,N代表长度，sum代表和)
    所以B_sum==B_N*(A_sum/A_N)为整数。我们试图找出这样B_N个数字，它们的和为B_N*(A_sum/A_N)。我们事先设定B_N<=C_N。
    
    思路：定义一个dp[i][j][k]代表是否可以在前i个数字中找到j个数字，它们的和为k。递推关系式：
    dp[i][j][k]=dp[i-1][j][k] || dp[i-1][j-1][k-A[i-1]];  //dp[i-1][j][k]代表A[i-1]没有参与，dp[i-1][j-1][k-A[n-1]]代表A[i-1]参与了。
    trick：
        1.因为dp[i]只依赖于dp[i-1],所以dp[i]的长度为2即可，因此使用i&1。
        2.(i*sum/len*len==i*sum)确保i*sum/len是整数。(因为B_N*(A_sum/A_N)为整数)
    
    
    */
    bool splitArraySameAverage(vector<int>& A) {
        int len=A.size();
        int sum=accumulate(A.begin(),A.end(),0);
        vector<vector<vector<bool>>> dp(2,vector<vector<bool>>(16,vector<bool>(300001,false))); //[2][k/2][]
        for(int i=0;i<=len;i++) dp[i & 1][0][0]=true;
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len/2;j++){
                for(int k=1;k<=sum;k++){
                    if(k>=A[i-1]){
                        dp[i & 1][j][k]=dp[i-1 & 1][j][k] || dp[i-1 & 1][j-1][k-A[i-1]];
                    }
                    else 
                        dp[i & 1][j][k]=dp[i-1 & 1][j][k];
                }
            }
        }
        for(int i=1;i<=len/2;i++){
            if((i*sum/len*len==i*sum) && (dp[len & 1][i][i*sum/len])) return true;
        }
        return false;
        
    }

    
    
    
    //自己写的，但是使用回溯会超时
    double avg;
    bool splitArraySameAverage1(vector<int>& A) {
        if(A.size()==0) return false;
        sort(A.begin(),A.end());
        avg=accumulate(A.begin(),A.end(),0)/(A.size()+0.0);
        cout<<avg<<endl;
        return helper(A,0,0,0);
        
    }
    
    bool helper(vector<int>& A,int sum,int count,int index){
        if(count!=0){
            double curr=sum/(count+0.000);
            if(curr>avg) return false;
            if(curr==avg){
                cout<<avg<<" "<<sum/(count+0.0)<<" "<<index<<endl;
                return true;
            }
        }
        if(helper(A,sum+A[index],count+1,index+1) || helper(A,sum,count,index+1)) return true;
        return false;
    }
    

    
    
    
// }



};