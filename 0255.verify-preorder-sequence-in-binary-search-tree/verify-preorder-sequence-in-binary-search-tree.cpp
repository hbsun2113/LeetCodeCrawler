class Solution {
public:
    // ????amazing?????https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/discuss/68142/Java-O(n)-and-O(1)-extra-space
    // ??????????????????????
    // ???????? https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/discuss/68185/C++-easy-to-understand-solution-with-thought-process-and-detailed-explanation
    bool verifyPreorder1(vector<int>& preorder) {
        int peek=INT_MIN;
        stack<int> s;
        for(int i=0;i<preorder.size();i++){
            if(peek>preorder[i]){
                // cout<<preorder[i]<<" "<<peek<<endl;
                return false;
            } 
            
            while(!s.empty() && preorder[i]>s.top()){ // ?????while?????????preorder[i]??????peek?????
                peek=s.top();                         // ?????preorder[i]??????????
                s.pop();
            }
            // ??preorder[i]?peek????,??????peek?????
            
            s.push(preorder[i]); // ?????????
        }
        return true;
    }
    
    // follow up???????:??????preorder????????
    bool verifyPreorder(vector<int>& preorder) {
        int peek=INT_MIN;
        int i=-1;
        for(auto p:preorder){
            if(peek>p) return false;
            while(i>=0 && p>preorder[i])
                peek=preorder[i--];
            preorder[++i]=p;
        }
        return true;
    }
};