class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,int> uml,umr;
        int res=1;
        for(const auto &n:nums){
            int nl=umr[n-1]; // n-1作为右边界的最大长度
            int nr=uml[n+1]; // n+1作为左边界的最大长度
            int sum=nl+1+nr;
            // cout<<n<<" "<<n-1-nl+1<<" "<<n+1+nr-1<<endl;
            uml[n-1-nl+1]=max(uml[n-1-nl+1],sum); // 更新左边界
            umr[n+1+nr-1]=max(umr[n+1+nr-1],sum); // 更新右边界
            res=max(sum,res);
        }
        return res;
    }
     

};