class Solution {
public:
    // 二刷，想想我为什么连result的vector都不需要
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        for(int i=0;i<T.size();i++){
            while(!s.empty() && T[i]>T[s.top()]){
                T[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            T[s.top()]=0;
            s.pop();
        }
        return T;
    }
    
    
        
    // 预警：下面有提示    
        
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    vector<int> dailyTemperatures1(vector<int>& T) {
        stack<int> s;
        vector<int> vec(T.size());
        for(int i=0;i<T.size();i++){
            while(!s.empty() && T[s.top()]<T[i]){
                vec[s.top()]=i-s.top();
                s.pop();
            }
            s.emplace(i);
        }
        return vec;
    }//终于自己会写单调栈了，可喜可贺！
};