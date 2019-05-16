class Solution {
public:
    
    
    
    // 二刷，还是没有做出来：
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        long long n=numerator;
        long long d=denominator;
        n=abs(n);
        d=abs(d);
        string res="";
        if((numerator>0 && denominator<0) || (numerator<0 && denominator>0)) res='-';
        res+=to_string(n/d);
        if(n%d==0) return res;
        
        res+=".";
        unordered_map<int,int> um;
        long long x=n%d;
        while(x!=0){
            if(um.find(x)!=um.end()){
                res=res.substr(0,um[x])+'('+res.substr(um[x])+')';
                return res;
            }
            um[x]=res.size();
            x*=10;
            res+=to_string(x/d);
            x%=d;
        }
        return res;
    }
    
    //自己没有做出来，看看https://www.acwing.com/solution/LeetCode/content/305/ 。 很郁闷
    // 写一下思路用来记忆：
    // 首先转换成long long避免出现转化符号时的溢出问题
    // 全部转换成正数，并记录结果的正负号
    // 先拿到整数部分
    // 然后是小数部分，注意分数不可能是无理数，要么是整除了(退出while循环，由最后返回结果)，要么就是无限循环小数（由while返回结果）。
    // 处理循环小数：每次将余数乘10再除以除数，当同一个余数出现两次时，我们就找到了循环节。
    string fractionToDecimal1(int numerator, int denominator) {
        unordered_map<long long,int> um;
        long long n=numerator, d=denominator;
        bool flag=false;
        if(n<0) n=-n,flag=!flag;
        if(d<0) d=-d,flag=!flag;
        string res=to_string(n/d);
        long long x=n%d;
        if(x==0){
            if(res!="0" && flag) res="-"+res;
            return res;
        }
        
        res+=".";
        while(x!=0){
            if(um[x]){
                res=res.substr(0,um[x])+"("+res.substr(um[x])+")";
                if(flag) res="-"+res;
                return res;
            }
            um[x]=res.size();
            x*=10;
            res+=to_string(x/d);
            x%=d;
        }
        
        if(flag) res="-"+res;
        return res;
    }
    
    
    
    string fractionToDecimal2(int _n, int _d) {
        long long n = _n, d = _d;
        bool minus = false;
        if (n < 0) minus = !minus, n = -n;
        if (d < 0) minus = !minus, d = -d;
        string res = to_string(n / d);
        n %= d;
        if (!n)
        {
            if (minus && res != "0") return '-' + res;
            return res;
        }

        res += '.';
        unordered_map<long long, int> hash;
        while (n)
        {
            if (hash[n])
            {
                res = res.substr(0, hash[n]) + '(' + res.substr(hash[n]) + ')';
                break;
            }
            else hash[n] = res.size();
            n *= 10;
            res += to_string(n / d);
            n %= d;
        }
        if (minus) res = '-' + res;
        return res;
    }

};