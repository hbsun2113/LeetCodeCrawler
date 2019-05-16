class Solution {
public:
    //自己做出来了，但是写了挺久，而且感觉不优雅
    vector<int> findClosestElements1(vector<int>& arr, int k, int x) {
        vector<int> result;
        auto it=upper_bound(arr.begin(),arr.end(),x);
        int l=1,r=0;
        while(result.size()<k){
            if(l<=distance(arr.begin(),it) && (r>=distance(it,arr.end()) || (x-*(it-l)<=*(it+r)-x))){
                result.push_back(*(it-l));
                l++;
            }
            else{
                result.push_back(*(it+r));
                r++;
            }
        }
        sort(result.begin(),result.end());
        return result;
    
    }
    
    
    //看别人的答案：
    //此解法致力于找到目标vector的左边界
    //https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC++Python-Binary-Research-O(log(N-K))
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=-1,r=arr.size()-k;//左边界的范围一定是在[0,arr.size()-k-1]
        while(l+1<r){
            int mid=l+(r-l)/2;
            cout<<mid<<endl;
            if(x-arr[mid]>arr[mid+k]-x) l=mid; //[mid,mid+k-1]没有[mid+1,mid+k]好。因为arr[mid+k]比arr[mid]更接近x，这说明目标vec的左边界还需要向左移。
            else r=mid;
        }
        return vector<int>(arr.begin()+r,arr.begin()+r+k);
    }
};