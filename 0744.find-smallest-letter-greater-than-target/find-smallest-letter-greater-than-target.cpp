class Solution {
public:
    
    //不是答案，我写这个函数是为了学习二分查找的边界条件。比如当所查找元素没有时，左边界和右边界的情况是怎么样的。
    char nextGreatestLetter4(vector<char>& letters, char target) {
        sort(letters.begin(),letters.end());
        int l=-1,r=letters.size();
        while(l+1!=r){
            int mid=l+(r-l)/2;
            if(letters[mid]==target){
                cout<<letters[mid]<<endl;
                break;
            }
            else if(letters[mid]<target) l=mid;
            else r=mid;
        }
        cout<<l<<" "<<r<<endl;
        cout<<letters[l]<<" "<<letters[r]<<endl;
        return letters[l];
    }
    
    
    
    
    //自己做的
    char nextGreatestLetter1(vector<char>& letters, char target) {
        letters.emplace_back(target); //先把自己插进去，避免处理找不到的情况
        unordered_set<char> tmp(letters.begin(),letters.end());
        letters.clear();
        for(const auto &l:tmp) letters.emplace_back(l);
        sort(letters.begin(),letters.end());
        if(target<letters[0]) return letters[0];
        if(target>=letters.back()) return letters[0];
        int l=-1,r=letters.size();
        while(l+1!=r){
            int mid=l+(r-l)/2;
            if(letters[mid]==target){
                return letters[mid+1];
            }
            else if(letters[mid]<target) l=mid;
            else r=mid;
        }
        return letters[0];
    }
    
    
    //自己做的。与上面不同，着重处理找不到的情况。感觉还是没有理解透彻,比如
    //```if(target>=letters.back()) return letters[0]```
    //可不可以去掉，换成最后处理？
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        //去重
        unordered_set<char> tmp(letters.begin(),letters.end());
        letters.clear();
        for(const auto &l:tmp) letters.emplace_back(l);
        
        sort(letters.begin(),letters.end());
        
        if(target<letters[0]) return letters[0];
        if(target>=letters.back()) return letters[0];
        
        int l=-1,r=letters.size();
        while(l+1!=r){
            int mid=l+(r-l)/2;
            cout<<mid<<endl;
            if(letters[mid]==target){
                return letters[mid+1];
            }
            else if(letters[mid]<target) l=mid;
            else r=mid;
        }    

        return letters[r];
    }
    
    
    //最简单的做法
    char nextGreatestLetter3(vector<char>& letters, char target) {
        auto res=upper_bound(letters.begin(),letters.end(),target);
        return res==letters.end()?letters[0]:*res;
    }
    
    
    //别人的做法，没有看明白
    char nextGreatestLetter2(vector<char>& letters, char target) {
        int n = letters.size();
       
        if (target >= letters[n - 1])   target = letters[0];
        else    target++;
        
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] == target)    return letters[mid];
            if (letters[mid] < target)     lo = mid + 1;
            else    hi = mid;
        }
        return letters[lo]; //return letters[hi];
    }
    
    
};