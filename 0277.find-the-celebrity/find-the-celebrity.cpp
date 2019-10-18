// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    // https://leetcode.com/problems/find-the-celebrity/discuss/71227/Java-Solution.-Two-Pass
    // ????1.?????? 2.???????????
    int findCelebrity(int n) {
        int res=0;
        for(int i=1;i<n;i++){
            if(knows(res,i)) res=i;
        }

        for(int i=0;i<n;i++){
            if( i<res && (!knows(i,res) ||  knows(res,i)) ) return -1;
            if( i>res && (!knows(i,res))) return -1;
        }
        
        return res;
    }
    
};