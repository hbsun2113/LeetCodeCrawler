class Solution {
public:
    //还是照抄了http://www.cnblogs.com/grandyang/p/4462810.html
    //思路也很简单：首先假设所有[2,n-1]的数组都是质数(flag=true)，然后遍历[2,n]，如果遇到了数字i发现它的flag是true那就真是质数了(因为之前的数字都没有组成它)，然后从头(2)到尾(小于n)找i能组成的非质数，把那些非质数的flag都设置为false。
    //这个方法好在，当遇到i时，就可以完全确定它是不是质数，而不用重新计算了。
    int countPrimes(int n) {
        int count=0;
        vector<bool> flag(n,true);
        for(int i=2;i<n;i++){
            if(flag[i]) count++;
            for(int j=2;j*i<n;j++) flag[j*i]=false;
        }
        return count;
    }
    
    
    
    
    
    //比较困惑的是有没有重复计算呢？我debug一下。
    //结论：果然是有重复计算的。Custom Testcase
    int countPrimes2(int n) {
        int count=0;
        vector<bool> flag(n,true);
        unordered_map<int,int> um;
        for(int i=2;i<n;i++){
            if(flag[i]) count++;
            for(int j=2;j*i<n;j++){
                flag[j*i]=false;
                um[j*i]++;
            }
        }
        
        for(const auto &u:um) cout<<u.first<<":"<<u.second<<endl;
        cout<<endl;
        
        return count;
    }
    

};


