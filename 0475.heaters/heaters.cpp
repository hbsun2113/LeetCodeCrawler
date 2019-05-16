class Solution {
public:
    
    // 三刷之一，很暴力，不如之前的submission，但是容易想到：
    // 针对每一个house，去找离他最近的heater，然后比较距离。
    int findRadius31(vector<int>& houses, vector<int>& heaters) {
        if(houses.size()==0 || heaters.size()==0) return 0;
        sort(heaters.begin(),heaters.end());
        int res=INT_MIN;
        for(const auto &h:houses){
            res=max(res,helper(heaters,h));
        }
        return res;
    }
    
    int helper(vector<int>& heaters, int h){
        
        auto it1=lower_bound(heaters.begin(),heaters.end(),h);
        
        // 有最优解直接返回：
        if(it1!=heaters.end() && *it1==h) return 0;
        
        // 无最优解，对左右进行比较：
        int res=INT_MAX;
        if(it1==heaters.begin()) res=min(res,abs(h-heaters[0]));
        else res=min(res,abs(h-*(it1-1)));
        if(it1==heaters.end()) res=min(res,abs(h-heaters.back()));
        else res=min(res,abs(h-*(it1)));
        return res;
    }
    
    
    
    
    
    
    // 二刷，自己又没有做出来。主要是之前没有太关注二分法中mid的作用，实话说现在也不是很清楚。
    int findRadius2(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int res=INT_MIN;
        for(const auto &h:houses){
            res=max(res,seekr(h,heaters));
        }
        return res;
    }
    
    int seekr(int h,vector<int>& heaters){
        int l=-1, r=heaters.size();
        int dis=INT_MAX;
        while(l+1!=r){
            int mid=l+(r-l)/2;
            int val=heaters[mid];
            if(val<h){
                l=mid;
                dis=min(dis,h-val);
            }
            else{
                r=mid;
                dis=min(dis,val-h);
            }
        }
        //if(r!=heaters.size() && heaters[r]==h) dis=0;
        return dis;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int findRadius1(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int result=0;
        for(const auto &h:houses){
            int distance=binary_helper(h,heaters);
            cout<<distance<<endl;
            result=max(result,distance);
        }
        return result;
    }
    
    //在heaters中寻找元素，使得最接近h。
    int binary_helper(int h,vector<int>& heaters){
        long long l=-1,r=heaters.size();
        int dis=INT_MAX; //需要时刻记录最小距离
        while(l+1!=r){
            long long mid=l+(r-l)/2;
            int heater=heaters[mid];
            if(heater<h){
                l=mid;
                dis=min(dis,h-heater);
            }
            else{
                r=mid;
                dis=min(dis,heater-h);
            }
        }
        if(r!=heaters.size() && heaters[r]==h) dis=0;
        return dis;
    }
    
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int res=0;
        for(const auto &h:houses){
            res=max(res,bh(heaters,h));
        }
        return res;
    }
    
    int bh(vector<int>& heaters, int house){
        int l=-1,r=heaters.size();
        int d=INT_MAX;
        while(l+1!=r){
            int mid=l+(r-l)/2;
            int h=heaters[mid];
            if(h<house){
                l=mid;
                d=min(d,house-h);
            }
            else{
                r=mid;
                d=min(d,h-house);
            }
        }
        return d;
    }
    
    
    
    
};