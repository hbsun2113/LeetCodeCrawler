class Solution {
public:
    //给定两个等长数组A和B。求A的排列，使得满足条件A[i] > B[i]的下标最多。

    
    //自己做出来的。但是这个时间复杂度太高了，肯定不是最优解。
    /*vector<int> advantageCount1(vector<int>& A, vector<int>& B) {
        for(int i=0;i<B.size();i++){
            int value=INT_MAX;
            int index=-1;
            int min_value=INT_MAX;
            int min_index=i;
            for(int j=i;j<A.size();j++){
                if(min_value>A[j]){
                    min_value=A[j];
                    min_index=j;
                }
                if(A[j]>B[i]){
                    if(value>A[j]){
                        value=A[j];
                        index=j;
                    }
                }
            }
            if(index!=-1){
                swap(A[i],A[index]);
            }
            else{
                swap(A[i],A[min_index]);
            }
        }
        return A;
    }*/
    
    
    
    
    //完全参考了 https://leetcode.com/problems/advantage-shuffle/discuss/149831/C++-6-lines-greedy-O(n-log-n)
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> ms(A.begin(),A.end());
        for(int i=0;i<B.size();i++){
            auto p= *(ms.rbegin())<=B[i]?ms.begin():ms.upper_bound(B[i]);
            A[i]=(*p);
            ms.erase(p);//一旦分配，对于下一轮来说肯定就是无效的了，所以要剔除出去。
        }
        return A;
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
};