class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int i=1,j=n;
        while(i<=j){
            //cout<<k<<endl;
            if(k>1){
                result.push_back(k--%2==0?i++:j--);
            }
            else result.push_back(j--);
        }
        return result;
    }
    
    
    
    /*vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1, j = n; i <= j; ) {
            if (k > 1) {
                res.push_back(k%2 == 0 ? i++ : j--);
                k--;
            }
            else
                res.push_back(j--);
        }
        return res;

    }*/
    
    
    
};