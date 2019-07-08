class Solution {
public:
    // https://leetcode.com/problems/majority-element-ii/discuss/63520/Boyer-Moore-Majority-Vote-algorithm-and-my-elaboration
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int t=nums.size()/3+1;
        
        int c1=0;
        int c2=0;
        int a=INT_MIN; // 任意值
        int b=a;
        for(const auto &n:nums){
            if(n==a) c1++; // 先看值，而不是看个数。这样更简单
            else if(n==b) c2++;
            else if(c1==0) a=n,c1=1;
            else if(c2==0) b=n,c2=1;
            else{
                c1--;
                c2--;
            }
            // cout<<n<<"..."<<a<<":"<<c1<<" | "<<b<<":"<<c2<<endl;
        }
        
        c1=0;
        c2=0;
        for(const auto &n:nums){
            c1+=(n==a);
            c2+=(n==b);
        }
        if(c1>=t) res.push_back(a);
        if(c2>=t) res.push_back(b);
        if(res.size()==2 && a==b) res.pop_back();
        
        return res;
    }
    
    // 自己写的，但是没有模板的感觉
    vector<int> majorityElement1(vector<int>& nums) {
        vector<int> res;
        int t=nums.size()/3+1;
        
        int c1=0;
        int c2=0;
        int a=INT_MIN; // 任意值
        int b=a;
        for(const auto &n:nums){
            
            if(c1==0 && n!=b) a=n;
            else if(c2==0) b=n;
            
            if(n==a) c1++;
            else if(n==b) c2++;
            else{
                c1--;
                c2--;                
            }
            // cout<<n<<"..."<<a<<":"<<c1<<" | "<<b<<":"<<c2<<endl;
        }
        
        c1=0;
        c2=0;
        for(const auto &n:nums){
            c1+=(n==a);
            c2+=(n==b);
        }
        if(c1>=t) res.push_back(a);
        if(c2>=t && (res.empty() || res[0]!=b) ) res.push_back(b);
        
        return res;
    }
};