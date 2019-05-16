class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        
        int l=0,r=numbers.size()-1,mid=0;
        while(true){
            
            if(numbers[l]+numbers[r]==target) {
                append(l,r,result);
                return result;
            }
            
        
            if(numbers[l]+numbers[r]<target) l++;
            else r--;
            
        }
        append(l,r,result);
        
        
        return result;
    }
    
    
    void append(int i,int j,vector<int> &result){
        result.push_back(i+1);
        result.push_back(j+1);
        return ;
    }
};