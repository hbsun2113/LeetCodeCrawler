class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int len=A.size();
        int left=-1,right=len;
        while(left+1!=right){
            int mid=left+(right-left)/2;
            if(A[mid]>A[mid-1] && A[mid]>A[mid+1]) return mid;
            if(A[mid]>A[mid-1]) left=mid;
            else right=mid;
        }
        return -1; //随便放回一个值即可。因为正确的值是直接在while循环里就返回了。
    }
};