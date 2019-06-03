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
    
    // https://leetcode.com/problems/longest-consecutive-sequence/discuss/41055/My-really-simple-Java-O(n)-solution-Accepted
    int longestConsecutive4(vector<int>& nums) {
        unordered_map<int,int> um;
        int res=0;
        for(const auto &n:nums){
            if(um[n]!=0) continue;
            int l=um[n-1];
            int r=um[n+1];
            int sum=l+1+r;
            um[n]=INT_MIN; //这行别忘了！但 只是一个标志，代表已经访问过了，不可以重新访问
            um[n-l]=sum; //真正要更新的是边界值 
            um[n+r]=sum;
            res=max(res,sum);
        }
        return res;
    }
    
    // 三刷没有做出来
    int longestConsecutive3(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,int> tr_right,tr_left;
        int res=1;
        for(const auto &n:nums){
            int left=tr_right[n-1];
            int right=tr_left[n+1];
            int len=left+right+1;
            tr_left[n-left]=max(tr_left[n-left],len);
            tr_right[n+right]=max(tr_right[n+right],len);
            res=max(res,len);
        }    
        return res;
    }
    
    //https://www.acwing.com/solution/LeetCode/content/222/
     // 自己画个图马上就能看明白吧
    int longestConsecutive1(vector<int>& nums) {
        unordered_map<int,int> right,left;
        int result=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int x=left[num+1]; //作为左端点的长度，段在右
            int y=right[num-1];//右端点，段在左
            int len=x+y+1;
            left[num-y]=max(left[num-y],len);
            right[num+x]=max(right[num+x],len);
            result=max(result,len);
        }
        return result;
    }
};