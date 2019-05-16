class Solution {
public:
    // 自己写的
    bool isUgly1(int num) {
        if(num<=0) return false;
        if(num==1) return true;
        if(num%2==0 && isUgly(num/2)){
            // cout<<"2:"<<num/2<<endl;
            return true;
        } 
        if(num%3==0 && isUgly(num/3)){
            // cout<<"3:"<<num%3<<endl;
            return true;
        }
            
        if(num%5==0 && isUgly(num/5)){
            // cout<<"5:"<<num/5<<endl;
            return true;
        } 
        return false;
    }
    
    
    //https://www.acwing.com/solution/LeetCode/content/298/
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        while (num % 2 == 0)
            num /= 2;
        while (num % 3 == 0)
            num /= 3;
        while (num % 5 == 0)
            num /= 5;
        return num == 1;
    }
    
};