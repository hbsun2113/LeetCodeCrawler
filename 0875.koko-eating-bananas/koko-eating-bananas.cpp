class Solution {
public:
    // 自己没有做出来：https://leetcode.com/problems/koko-eating-bananas/discuss/152324/C++JavaPython-Binary-Search
    // 一点感悟：凡是要缩小搜索空间的，都可以考虑是否可以使用 二分查找
    int minEatingSpeed(vector<int>& piles, int H) {
        int maxspeed=*max_element(piles.begin(),piles.end());
        int l=0,r=maxspeed+1;
        while(l+1!=r){
            int mid=l+(r-l)/2;
            if(timecost(piles,mid)>H) l=mid;
            else r=mid;
        }
        cout<<timecost(piles,r);
        return r;
    }
    
    int timecost(vector<int>& piles,int spe){
        int result=0;
        for(const auto &p:piles){
            result+=(p+spe-1)/spe;
        }
        return result;
    }
};