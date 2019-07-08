#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    // 二刷没有做出来
    vector<int> pourWater(vector<int>& h, int V, int K) {
        for(int i=0;i<V;i++){
            int l=K,r=K;
            while(l-1>=0 && h[l]>=h[l-1]) l--;
            while(l<K && h[l]==h[l+1]) l++;
            while(r+1<h.size() && h[r]>=h[r+1]) r++;
            while(r>K && h[r]==h[r-1]) r--;
            if(h[l]<h[K]) h[l]++;
            else h[r]++;
        }
        return h;
    }
    
    
    // 自己没有做出来，这个还是很巧妙的 https://www.cnblogs.com/grandyang/p/8460541.html
    vector<int> pourWater1(vector<int>& heights, int V, int K) {
        int n=heights.size();
        while(--V>=0){
            int l=K,r=K;
            while(l>=1 && heights[l-1]<=heights[l]) l--;
            while(l<K && heights[l]==heights[l+1]) l++;
            while(r+1<n && heights[r+1]<=heights[r]) r++;
            while(r>K && heights[r]==heights[r-1]) r--;
            if(heights[l]<heights[K]) heights[l]++;
            else heights[r]++;
        }
        return heights;
    }
};