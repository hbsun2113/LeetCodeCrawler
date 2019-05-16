class Solution {
public:
    //第一次参加比赛，遇到这个问题直接就跪了。参考了https://leetcode.com/problems/maximum-width-ramp/discuss/208348/JavaC%2B%2BPython-O(N)-Using-Stack/212279
    //这种值和索引强相关的问题，肯定是要在数据结构中保存索引，下回注意要想到这一点。
    //整体思路很简单，就是先从左到右，维护一个降序结构的栈，作为左边界的候选。
    //然后从右向左遍历每个元素，以它为右边界，极尽所能找到它的左边界。
    int maxWidthRamp1(vector<int>& A) {
        stack<int> s;//一个降序的栈，只有当前值比历史值小，才有存储的意义，否则它一定不会是最大Width的左边界。
        //想想为什么要用栈，肯定是用到了栈后进先出的特点。
        //再一想，可能没有用到“后进先出的特点”，只是更容易维护一个降序的结构。
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i){
            if (s.empty() || A[s.top()] > A[i]){
                //if(!s.empty()) cout<<A[s.top()]<<" "<<A[i]<<"-----"<<s.top()<<" "<<i<<endl;
                s.push(i);
            }       
        }
            
        
        for (int i = n - 1; i > res; --i) //i如果小于res,那即使左边界是0位置，i也没有意义了。
            while (!s.empty() && A[s.top()] <= A[i]){  //对右边的每个元素，极尽所能找到它的左边界。
                res = max(res, i - s.top());
                //cout<<"result:"<<i<<" "<<s.top()<<endl;
                s.pop();//如果后续有更大的res，左边界也肯定不会是s.top(),因此它没有意义了，可以扔出去了。无论是否是当前的右边界！
            }
        return res;
    }
    
    
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        for(int i=0;i<A.size();i++){
            if(s.empty() || A[s.top()]>A[i]) s.emplace(i);
        }
        
        int w=0;
        for(int i=A.size()-1;i>=0;i--){
            while(!s.empty() && (A[i]>=A[s.top()])){
                w=max(w,i-s.top());
                s.pop();
            }
        }
        return w;
    }
    
    
    
    
    
    
    
};