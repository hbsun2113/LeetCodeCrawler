class Solution {
public:
    // https://leetcode.com/problems/longest-chunked-palindrome-decomposition/discuss/350762/Java-0ms-concise-beats-100-(both-time-and-memory)-with-algo
    int longestDecomposition(string s) {
        if(s.size()==0) return 0;
        int n=s.size();
        for(int i=1;i<=n/2;i++){
            string first=s.substr(0,i);
            string second=s.substr(n-1-i+1,i);
            if(first==second){
                string tmp=s.substr(i,n-1-i+1-1-i+1);
                // cout<<first<<" "<<tmp<<endl;
                return 2+longestDecomposition(tmp);
            } 
        }
        return 1;
    }
};