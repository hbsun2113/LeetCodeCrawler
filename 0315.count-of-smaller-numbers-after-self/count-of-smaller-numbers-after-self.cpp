class Solution {
public:
    // 模板题：https://leetcode.com/problems/reverse-pairs/description/
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> vec(nums.size()); 
        vector<int> res(nums.size(),0);
        if(nums.size()==0) return res;
        for(int i=0;i<nums.size();i++){
            vec[i]=make_pair(nums[i],i); // 要保存索引，不是为了比较，而是为了定位
        }
        
        merge(nums,0,nums.size()-1,res,vec);
        return res;
    }
    
    void merge(vector<int> &nums, int l, int r, vector<int> &res, vector<pair<int,int>> &vec){
        if(l>=r) return ;
        int mid=l+r>>1;
        merge(nums,l,mid,res,vec);
        merge(nums,mid+1,r,res,vec);
        
        
        // 好了，现在两个子数组分别排好序了
        vector<pair<int,int>> tmp(r-l+1);
        int i=l,j=mid+1,k=0,p=mid+1;
        while(i<=mid){ // 针对每个i，j肯定是在i后面了，就看nums[j]是否小于nums[i]了
            while(p<=r && vec[i].first>vec[p].first) p++;
            res[vec[i].second]+=(p-(mid+1)); // 因为更改了数组nums原本的顺序，而我们又要定位res，所以才要保存索引的位置
            while(j<=r && vec[j].first<=vec[i].first) tmp[k++]=vec[j++];
            tmp[k++]=vec[i++];
        }
        while(j<=r) tmp[k++]=vec[j++];
        move(tmp.begin(),tmp.end(),vec.begin()+l);
    }
    
    
    
    
    // 二分法+插入
    vector<int> countSmaller1(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> val;
        for(int k=nums.size()-1;k>=0;k--){
            int target=nums[k];
            int l=0,r=val.size()-1;
            // 找到最后一个小于自己的数字[l,mid-1],[mid,r]
            while(l<r){
                int mid=l+r+1>>1;
                if(val[mid]<target) l=mid;
                else r=mid-1;
            }
            if(val.empty() || val[r]>=target) res[k]=0; // 这道题目有点特殊，使用l,而不能使用r，因为如果val.size()==0时，l!=r
            else res[k]=l+1;
            val.insert(val.begin()+res[k],target);
        }
        return res;
    }
    
};