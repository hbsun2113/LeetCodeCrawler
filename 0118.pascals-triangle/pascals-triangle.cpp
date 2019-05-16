//这个写的风格奇差，主要是因为递推关系找得不好。
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = vector<vector<int>>();
        if(numRows==0) return result;
        vector<int> tmp;
        tmp.push_back(1);
        result.push_back(tmp);
        if(numRows==1) return result;
        tmp.push_back(1);
        result.push_back(tmp);
        queue<vector<int>> q;
        q.push(tmp);
        if(numRows==2) return result;
        int length = 3;
        while(length <= numRows){
            length++;
            tmp=q.front();
            q.pop();
            vector<int> part;
            part.push_back(1);
            for(int i=0;i<tmp.size()-1;i++){
                int sum=tmp[i]+tmp[i+1];
                part.push_back(sum);
            }
            part.push_back(1);
            result.push_back(part);
            q.push(part);
        }
        return result;
    }
};