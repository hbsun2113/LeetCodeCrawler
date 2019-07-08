class Solution {
public:
    Solution(){ 
        return ; // 暴力建表TLE
        vec.push_back({});
        int c=1;
        vector<int> tmp;
        for(int i=0;i<=19;i++){
            tmp.clear();
            for(int j=1;j<=pow(2,i);j++) tmp.push_back(c++);
            if(i%2==0) reverse(tmp.begin(),tmp.end());
            vec.push_back(tmp);
        }
    }
    
    // 自己做的：
    vector<vector<int>> vec;
    vector<int> res;
    vector<int> pathInZigZagTree(int label) {
        res.push_back(label);
        
        int r=log2(label)+1;
        int maxv=pow(2,r)-1;
        int minv=pow(2,r-1);
        int c;
        if(r%2==0) c=maxv-label+1;
        else c=label-minv+1;
        c++;
        c/=2;
        for(int i=r-1;i>=1;i--){
            if(i%2==0){
                maxv=pow(2,i)-1;
                res.push_back(maxv-c+1);
            } 
            else{
                minv=pow(2,i-1);
                res.push_back(c+minv-1);
            } 
            c++; // 由儿子找父亲，要先加1,再除以2，画个图就知道了,注意这个因为我们从1开始计数的。如果从0开始计数，就不用先+1.
            c/=2;
        }
        
        reverse(res.begin(),res.end());
        return res;   
    }
    
    // 这个可能更make sense
    // https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/discuss/323293/C++-O(log-n)

    
    
    
    
};