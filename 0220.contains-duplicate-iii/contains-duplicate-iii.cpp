class Solution {
public:
    // 这个解法实在是很trick了 使用了分桶思想
    // https://leetcode.com/problems/contains-duplicate-iii/discuss/61645/AC-O(N)-solution-in-Java-using-buckets-with-explanation
    // 大致看了楼主的帖子，然后是comments揭露了本质 @wzrthhj @WendyO__O
    // bucket_size要+1：避免了t为0时的除法。另外，本来就应该是t+1的，假设t=3,则[0,1,2,3]应该被分到一个桶中。0和3除以4都为0
    // remapn：需要重hash，是因为负数在除以整数的时候会向0靠近，这样把不应该分为一桶的数分到一桶里，例如t=2,则[0,1,2]应该在一桶，但是如果有-1，则变成了[-1,0,1,2],而distance(-1,2)大于了t，因此有问题。如果我们找到一个base，然后根据距离base的距离来进行分桶，就避免了负数的尴尬问题
    // 相邻桶中元素也需要做比较的原因(remapn-bucket_set[bucketid-1]<=t)：假如桶是这样的[[1,2,3],[4,5,6]],我们发现3和4的距离其实也是小于t的，即两个相邻桶中的元素也可能符合条件
    // bucket_set[bucketid]=remapn;会把之前的元素替换掉，但不会有问题的原因：我之前担心这个会影响相邻桶中元素做比较(假如有A、B两个桶，A中本来有一个元素a1距离B中元素b是小于t的，但是又来了一个a2将a1替换掉了，这样等到遍历到b时就不会发现a1了)。但这个其实不会影响，因为我们把上述顺序打出来看一下：a1->a2->b，当遍历到a2时，就会发现a1已经和自己落到同一个桶中了，直接return true，都等不到遍历到b。
    // 我们上面只考虑了t的限制，没有考虑到位置k的限制。解决方案：我们通过动态删除bucket_set元素，保证了当遍历到元素x时，桶中的元素的位置距离x一定是小于等于k的。
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t<0 || k<0) return false;
        
        long long bucket_size=0ll+t+1;
        unordered_map<long long , long long> bucket_set;
        
        for(int i=0;i<nums.size();i++){
            long long n=nums[i];
            long long remapn = 0ll+n-INT_MIN;
            long long bucketid = remapn/bucket_size;
            if(bucket_set.find(bucketid)!=bucket_set.end()) return true;
            if(bucket_set.find(bucketid-1)!=bucket_set.end() && remapn-bucket_set[bucketid-1]<=t) return true;
            if(bucket_set.find(bucketid+1)!=bucket_set.end() && bucket_set[bucketid+1]-remapn<=t) return true;
            
            bucket_set[bucketid]=remapn;
            
            if(bucket_set.size()>k){
                long long remapdeleten = 0ll+nums[i-k]-INT_MIN;
                long long deletebucketid=remapdeleten/bucket_size;
                bucket_set.erase(deletebucketid);
            }
        
        }
        
        return  false;
    }
    
    
    
    // 自己写的 暴力解法
    bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
        // cout<<nums.size()<<" "<<k<<" "<<t<<endl;
        if(k<t) return k_is_samller(nums,k,t);
        else return t_is_samller(nums,k,t);
    }
    
    // 遍历位置
    bool k_is_samller(vector<int>& nums, int k, int t){ 
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;(j<nums.size() && j-i<=k);j++){
                if(llabs(nums[i]+0ll+-nums[j])<=t) return true;
            }
        }
        return false;
    }
    
    // 遍历值
    bool t_is_samller(vector<int>& nums, int k, int t){
        unordered_map<long long,int> um;  //value->position
        for(int i=0;i<nums.size();i++){
            
            int v=nums[i];
            int p=i;
            
            for(int i=0;i<=t;i++){
                if(um.find(v+0ll-i)!=um.end() && abs(um[v-i]-p)<=k) return true;
                if(um.find(v+0ll+i)!=um.end() && abs(um[v+i]-p)<=k) return true;
            }
            
            um[v]=p;
        
        }
        
        return false;
    } 
};