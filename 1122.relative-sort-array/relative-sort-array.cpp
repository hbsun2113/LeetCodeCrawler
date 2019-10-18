class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> um1;
        unordered_map<int,int> um2;
        for(const auto &n:arr1) um1[n]++;
        for(const auto &n:arr2) um2[n]++;
        vector<int> vec;
        for(const auto &t:um1){
            if(um2.find(t.first)==um2.end()){
                for(int k=0;k<um1[t.first];k++)
                    vec.push_back(t.first);
            } 
        }
        sort(vec.begin(),vec.end());
        int i=0;
        for(const auto &n:arr2){
            for(int k=0;k<um1[n];k++) 
                arr1[i++]=n;
        }
        for(const auto &n:vec){
            arr1[i++]=n;
        }
        return arr1;
    }
};