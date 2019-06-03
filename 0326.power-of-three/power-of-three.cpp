class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if (0 >= n)
            return false;

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
    
    bool isPowerOfThree4(int n) {
        if(n<=0) return false;
        while(n!=1){
            if(n%3) return false;
            n/=3;
        }
        return true;
    }
    
    // https://www.acwing.com/activity/content/problem/content/194/1/
    bool isPowerOfThree3(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
    
    
    bool isPowerOfThree2(int n) {
        if(n==0) return false;
        if(n==1) return true;
        double num=n;
        while(num>1){
            num/=3.0;
        }
        return num==1; 
    }
    
    bool isPowerOfThree1(int n) {
        if(n==0) return false;
        if(n==1) return true;
        priority_queue<long long> p;
        p.emplace(3);
        while(!p.empty()){
            auto t=p.top();
            if(t==n) return true;
            if(t>n) return false;
            p.pop();
            p.emplace(3*t);
        }
        return false;
    }
};