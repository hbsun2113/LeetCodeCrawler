class Solution {
public:
    const long long MOD=1e9+7;
    int numPrimeArrangements(int n) {
        // if(n<=1) return 0;
        vector<int> vec(n);
        int prime_cnt=0;
        for(int i=1;i<=n;i++) 
            if(isprime(i)) prime_cnt++;
        cout<<prime_cnt<<endl;
        return cal(prime_cnt)*cal(n-prime_cnt)%MOD;
    }
    
    long long cal(int n){
        long long sum=1;
        for(int i=1;i<=n;i++){
            sum=(sum*i)%MOD;
        }
        return sum;
    }
    
    bool check(vector<int> &vec){
        for(int i=0;i<vec.size();i++){
            if(isprime(vec[i]) && !isprime(i+1)) return false;
        }
        return true;
    }
    
    
    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2;i<n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
};