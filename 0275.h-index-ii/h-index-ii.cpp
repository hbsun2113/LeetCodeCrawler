class Solution {
public:
    // 三刷，闫学灿的逻辑走一遍
    // check逻辑：引用数目要大于合格的文章数目
    // 在满足check逻辑的条件下，解在左区间(右面都满足，解肯定在左面)，所以动右边界r=mid
    // 然后相应写出：l=mid-1 和 int mid=(l+r)/2;
    int hIndex(vector<int>& citations) {
        if(citations.size()==0) return 0;
        int n=citations.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(citations[mid]>=n-mid)  r=mid;
            else l=mid+1;
        }
        if(citations[l]>=n-l) return n-l;
        return 0;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //二刷
    int hIndex2(vector<int>& citations) {
        if(citations.size()==0) return 0;
        int l=-1,r=citations.size();
        while(l+1!=r){
            int mid=l+(r-l)/2;
            int h=citations[mid];
            int len=citations.size()-mid;
            if(h<len) l=mid;
            else r=mid;
        }
        //r是第一个h>=len的位置(引用量 大于等于 满足条件的文章的数目 的位置)
        return citations.size()-r;
    }
    
    
    int hIndex1(vector<int>& citations) {
        int l=-1,r=citations.size();
        while(l+1!=r){
            int mid=(r-l)/2+l;
            int len=citations.size()-mid;
            int citation=citations[mid];
            if(len>citation) l=mid;
            else r=mid;
        }
        //要么返回了正好符合条件的，要么返回文章数量少、但是引用量上去的第二顺位。
        return citations.size()-r;
    }
};