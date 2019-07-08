class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res(n,0);
        if(n==0) return res;
        int c=1;
        int i=0;
        while(candies>0){
            if(candies>=c){
                res[i]+=c;
                candies-=c;
                c++;
                i++;
                i%=n;
                
            }
            else{
                res[i]+=candies;
                candies-=candies;
            }
        }
        return res;
    }
};