class Solution {
public:
    // https://zxi.mytechroad.com/blog/greedy/leetcode-915-partition-array-into-disjoint-intervals/
    // key?????????????????????????????????????
    int partitionDisjoint(vector<int>& A) {
        int left_max=A[0],cur_max=A[0],left_len=1;
        for(int i=1;i<A.size();i++){
            if(A[i]<left_max){ // ??A[i]???????left subarrays?
                left_max=cur_max; // ?????cur_max??????left subarrays????????left_max
                left_len=i+1;
            }
            else 
                cur_max=max(cur_max,A[i]);
        }
        return left_len;
    }
    
    int partitionDisjoint1(vector<int>& A) {
        multiset<int> left,right;
        left.insert(A[0]);
        right.insert(A.begin()+1,A.end());
        for(int i=1;i<A.size();i++){
            auto maxv=*(left.rbegin());
            auto minv=*(right.begin());
            if(maxv<=minv) return i;
            left.insert(A[i]);
            right.erase(right.find(A[i]));
        }
        return -1;
    }
};