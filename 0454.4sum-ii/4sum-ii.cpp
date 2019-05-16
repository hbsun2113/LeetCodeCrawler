class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len=A.size();
        map<int,int> m;
        int result=0;
        for(int a=0;a<len;a++)
            for(int b=0;b<len;b++){
                int sum=A[a]+B[b];
                m[-sum]++;
            }
        
        for(int c=0;c<len;c++)
            for(int d=0;d<len;d++){
                int sum=C[c]+D[d];
                auto it=m.find(sum);
                if(it!=m.end()){
                    result+=it->second;
                }
            }
          
        return result;
    }
};