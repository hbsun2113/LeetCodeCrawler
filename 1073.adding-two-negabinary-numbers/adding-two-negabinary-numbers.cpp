class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> vec;
        int carry=0;
        int i=arr1.size()-1,j=arr2.size()-1;
        while(i>=0 || j>=0 || carry!=0){
            if(i>=0) carry+=arr1[i--];
            if(j>=0) carry+=arr2[j--];
            vec.push_back(carry&1);
            carry=-(carry>>1);
        }
        while(vec.size()>1 && vec.back()==0) vec.pop_back();
        reverse(vec.begin(),vec.end());
        return vec;
    }
};