#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    // https://leetcode.com/problems/longest-well-performing-interval/discuss/334565/JavaC++Python-O(N)-Solution-Life-needs-996-and-669       Explanation????
    /*
     0  1  2 3 4
     6  6  9 9 9
    -1 -2 -1 0 1
    
    */
    int longestWPI1_2(vector<int>& h) {
        int n=h.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            if(h[i]>8) dp[i]=1;
            else dp[i]=-1;
        }
        
        unordered_map<int,int> um;
        int cur=0;
        int res=0;
        for(int i=0;i<n;i++){
            cur+=dp[i];
            // cout<<i<<" "<<cur<<endl;
            if(cur>0) res=i+1;
            else{
                if(um.find(cur)==um.end()) um[cur]=i;
                if(um.find(cur-1)!=um.end()) res=max(res,i-um[cur-1]); // ??????????????????????????
            }
        }
        return res;
    }
    
    // neal_wu contest 145??????
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        for (int i = 0; i < n; i++)
            hours[i] = hours[i] > 8 ? +1 : -1;

        vector<int> sums(n + 1, 0);

        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + hours[i];

        int best = 0;

        for (int i = 0; i < n; i++)
            for (int j = n; j > i && j - i > best; j--)
                if (sums[i] < sums[j]) // ???????????????
                    best = j - i;

        return best;
    }
    
    
    // ????????????4?
    int longestWPI1_1(vector<int>& h) {
        int n=h.size();
        int maxv=0;
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            if(h[i]>8){
                dp[i]=1;
                maxv=1;
            } 
            else dp[i]=0;
        }
        vector<int> presum(n+1); // ??????????
        for(int i=1;i<=n;i++){
            presum[i]=presum[i-1]+dp[i-1];
        }
        // dbv(presum);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){ // ???????TLE
                if(presum[i]-presum[j-1]>(i-j+1)/2){
                    // cout<<i<<" "<<j<<endl;
                    if(maxv<i-j+1) maxv=i-j+1;
                    break;
                }
            }
        }
        return maxv;   
    }
};