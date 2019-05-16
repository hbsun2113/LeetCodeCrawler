class Solution {
public:
    //完全参考了https://www.cnblogs.com/grandyang/p/5078490.html，自己没有做出来。
    //感觉自己对二分法还是很不熟练！！需要系统学习！
    vector<int> countSmaller1(vector<int>& nums) {
        vector<int> result(nums.size());
        vector<int> nv;
        for(int i=nums.size()-1;i>=0;i--){
            int l=0,r=nv.size();
            while(l<r){
                int mid=l+(r-l)/2;
                if(nv[mid]<nums[i]) l=mid+1;
                else r=mid;
            }
            cout<<nums[i]<<" "<<r<<" "<<nv.size()<<endl;
            result[i]=r;
            //if(r>nv.size()) return result;
            nv.insert(nv.begin()+r,nums[i]);
        }
        return result;
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size());
        vector<int> nv;
        for(int i=nums.size()-1;i>=0;i--){
            int d=distance(nv.begin(),lower_bound(nv.begin(),nv.end(),nums[i]));
            result[i]=d;
            nv.insert(nv.begin()+d,nums[i]);
        }
        return result;
    }
};