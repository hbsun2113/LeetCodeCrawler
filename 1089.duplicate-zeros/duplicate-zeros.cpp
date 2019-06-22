class Solution {
public:
    // space O(1)的方法：https://leetcode.com/problems/duplicate-zeros/discuss/312743/JavaC++-O(n)-or-O(1)
    void duplicateZeros(vector<int>& arr) {
        if(arr.empty()) return;
        vector<int> tmp(arr);
        int i=0;
        int j=0;
        while(j<arr.size()){
            if(tmp[i]==0){
                arr[j++]=0;
                if(j<arr.size()) arr[j]=0;
            }
            else{
                arr[j]=tmp[i];
            }
            i++;
            j++;
        }
    }
    
    // 更简便
    void duplicateZeros1(vector<int>& arr) {
        vector<int> x;
        for(int i = 0 ; i < arr.size() ; i++){
            x.push_back(arr[i]);
            if( arr[i] == 0 ) x.push_back(arr[i]);
        }
        for(int i = 0 ; i < arr.size() ; i++)
            arr[i] = x[i];
        return;
    }
};