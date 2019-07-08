/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    // 1. 先找到山顶元素(只有一个山顶，感觉题目说错了)
    // 2. 在第一段有序(递增)序列中找target
    // 3. 在第二段有序(递减)序列中找target
    // 根据weiyanthor在lee215下的评论，这题目中对get的限制非常宽松，可以等同为没有：
    // O(log 10000)==4 远远小于 100
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int ll=0,rr=mountainArr.length()-1;
        int l=ll,r=rr;
        while(l<r){
            int mid=l+r>>1;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)) r=mid;
            else l=mid+1;
        }
        int peek=l;
        cout<<"peek="<<mountainArr.get(peek)<<endl;
        
        l=ll,r=peek;
        while(l<r){
            int mid=l+r>>1;
            int t=mountainArr.get(mid);
            if(t==target) return mid;
            if(t>target) r=mid;
            else l=mid+1;
        }
        if(mountainArr.get(l)==target) return l;// 处理边界问题
        
        l=peek,r=rr;
        while(l<r){
            int mid=l+r>>1;
            int t=mountainArr.get(mid);
            if(t==target) return mid;
            if(t<target) r=mid;
            else l=mid+1;
        }
        if(mountainArr.get(l)==target) return l;
        
        return -1;
        
    }
};