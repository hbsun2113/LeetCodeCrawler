class Solution {
public:
    // 二刷
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> p;
        p.emplace(1);
        long long pre=0;
        while(1){
            long long t=p.top();
            p.pop();
            // cout<<"t="<<t<<" | ";
            if(t<=pre) continue;
            pre=t;
            if(--n==0) return t;
            p.emplace(2*t);
            p.emplace(3*t);
            p.emplace(5*t);
        }
        return INT_MIN;
    }
    
    
    //https://leetcode.com/problems/ugly-number-ii/discuss/69364/My-16ms-C++-DP-solution-with-short-explanation
    /*
    1. entially, we have to multiply the existed ugly numbers by 2, 3 and 5 to get a bigger ugly number, however, if we blindly multiply all the existed numbers by 2, 3 and 5, then the number could grow much faster than needed
    2. Hence, every time we only try to find the next smallest ugly number
    3. Also, since any existed number will be multiplied by 2, 3 and 5 once and only once, otherwise duplicate, we can use a pointer to keep track of where the 2, 3 and 5 are going to multiply in the next step.
    4. Once, we find the next minimum, we can move on the corresponding pointer, otherwise it always stays at the already existed ugly number which would makes pointer useless
    */
    
    // 每个ugly数都是由已知的ugly数乘上2、3、5组成的。因此我们要对每个数乘上2、3、5。
    // 问题是如何顺序得到ugly数：小的ugly*5可能大于大的ugly*2。
    // 逆向思维：由于每个数都要乘上2、3、5,所以我们声明3个指针标明2、3、5分别运动到什么位置了，然后在这三个结果中取最小值作为下一个ugly数，并且同步更新相应的指针。
    // dp,bottom-up
    int nthUglyNumber1(int n) {
        vector<int> vec(n);
        int p2=0,p3=0,p5=0;
        vec[0]=1;
        for(int i=1;i<n;i++){
            int n2=vec[p2]*2;
            int n3=vec[p3]*3;
            int n5=vec[p5]*5;
            int res=min(n2,min(n3,n5));
            if(res==n2) p2++;
            if(res==n3) p3++;
            if(res==n5) p5++;
            vec[i]=res;
        }
        return vec.back();
        
    }
    
    
    
    
    
    // https://www.acwing.com/solution/LeetCode/content/286/
    //  不理解这个为什么要用long long，而上面直接使用int就可以了？
    int nthUglyNumber2(int n) {
        priority_queue<long long> pq; //最大堆，为了找最小，我们改变符号
        pq.emplace(-1);
        int prev=1;
        for(int i=1;i<=n;i++){
            long long tmp=pq.top();
            pq.pop();
            if(tmp==prev){
                i--;
                continue;
            }
            pq.emplace(tmp*2);
            pq.emplace(tmp*3);
            pq.emplace(tmp*5);
            prev=tmp;
        }
        return -1*prev;
        
    }
};