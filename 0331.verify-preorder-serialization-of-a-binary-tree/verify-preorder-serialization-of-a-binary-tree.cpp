class Solution {
public:
    //https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/discuss/78554/C++-4ms-solution-O(1)-space-O(n)-time
    // 自己没有做出来
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // 要点：每个非空节点都应该有两个儿子
    bool isValidSerialization(string preorder) {
        preorder+=","; //为了看看最后一个元素是否合格，因此在加一个","。
        int cap=1; //cap代表我们还需要遍历的节点数目。一开始只知道有根，所以是1个。根也可能为nullptr。
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]!=',') continue; //以","为单位处理节点。因为一旦遇到","就标志着它之前的这个节点结束了，我们可以着手处理这个节点。
            cap--;
            if(cap<0) return false;
            if(preorder[i-1]!='#') 
                cap+=2;
        }
        return cap==0;
    }
};
    
    
    
    