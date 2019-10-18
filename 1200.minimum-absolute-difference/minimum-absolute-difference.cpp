class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        if(arr.size()==0) return res;
        sort(arr.begin(),arr.end());
        int dis=INT_MAX;
        for(int i=1;i<arr.size();i++){
            dis=min(dis,arr[i]-arr[i-1]);
        }
        
        for(int i=1;i<arr.size();i++){
            if(dis==arr[i]-arr[i-1])
                res.push_back({arr[i-1],arr[i]});
        }
        
        return res;
    }
};