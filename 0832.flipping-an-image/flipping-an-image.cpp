class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto &a:A){
            change(a);
        }
        return A;
    }
    
    void change(vector<int> &A){
        int i=0,j=A.size()-1;
        while(i<j){
            swap(A[i],A[j]);
            A[i]=1-A[i];
            A[j]=1-A[j];
            i++;
            j--;
        }
        if(i==j) A[i]=1-A[i];
        
    }
};

//0 1 2