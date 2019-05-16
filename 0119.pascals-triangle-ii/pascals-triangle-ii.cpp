//经验题：https://www.cnblogs.com/springfor/p/3887913.html。
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1);
        result[0]=1;
        for(int i=0;i<rowIndex+1;i++){//其实外循环就是挨层算的。
            for(int j=i;j>0;j--){
                result[j]=result[j]+result[j-1];
            }
        }
        return result;
    }
};