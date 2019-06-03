class Solution {
public:
    // slidding windows
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        if(customers.size()==0) return 0;
        int sum=0;   // 代表没有X覆盖的，本应该得到的值
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        
        int curr=0;  // 代表区间之和
        int res=sum; 
        for(int j=0;j<grumpy.size();j++){
            curr+=customers[j];
            if(grumpy[j]==0) sum-=customers[j];
            
            cout<<curr<<" "<<sum<<endl;
            cout<<"continue:"<<j<<" "<<j-X+1<<" "<<endl;
            if(j-X+1<0) continue;
            res=max(res,sum+curr); // 看看当前窗口的最终结果
            
            if(grumpy[j-X+1]==0) sum+=customers[j-X+1]; // 因为窗口要向右移动，所以率先减去当前左边界
            curr-=customers[j-X+1];
        }
        
        return res;
    }
};