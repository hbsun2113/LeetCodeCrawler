class Solution {
public:
    // https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C++Java-with-picture-prefixed-sliding-window?orderBy=most_votes
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int res=0;
        int cnt=0;
        int prefix=0;
        unordered_map<int,int> um;
        for(int i=0,j=0;j<A.size();j++){
            if(um[A[j]]++==0) cnt++;
            if(cnt==K+1){
                um[A[i]]--;
                i++;
                cnt--;
                prefix=0;
            }
            while(um[A[i]]>1){
                um[A[i]]--;
                i++;
                prefix++;
            }
            if(cnt==K) res+=(prefix+1);
        }
        return res;
    }
    
    
    // 更好复现：https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/234482/JavaC++Python-Sliding-Window-with-Video?orderBy=most_votes
};