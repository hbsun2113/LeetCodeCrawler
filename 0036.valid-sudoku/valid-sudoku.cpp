class Solution {
public:
    //利用了map就做麻烦了，参考一下这个吧：https://www.cnblogs.com/sunshineatnoon/p/3858132.html
    bool isValidSudoku1(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()==0) return true;
        int row=board.size(),col=board[0].size();
        // cout<<" "<<col<<" "<<row<<endl;
        for(int i=0;i<row;i++){
            vector<char> tmp=board[i];
            unordered_map<char,int> test;
            for(auto & c:tmp){
                if(c!='.'){
                    test[c]+=1;
                    if(test[c]>1) return false;
                }
            }
            tmp.clear();
            test.clear();
        }
        for(int i=0;i<col;i++){
            vector<char> tmp;
            for(int j=0;j<row;j++){
                tmp.push_back(board[j][i]);
            }
            unordered_map<char,int> test;
            for(auto & c:tmp){
                if(c!='.'){
                    test[c]+=1;
                    if(test[c]>1) return false;
                }
            }
            tmp.clear();
            test.clear();
        }
        vector<char> tmp;
        unordered_map<char,int> test;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int m=i*3;m<i*3+3;m++){
                    for(int n=j*3;n<j*3+3;n++){
                        tmp.push_back(board[m][n]);
                    }
                }
                for(auto & c:tmp){
                if(c!='.'){
                    test[c]+=1;
                    if(test[c]>1) return false;
                }
            }
            tmp.clear();
            test.clear();
            }
        }
        
    return true;    
    }
    
    
    
    bool isValidSudoku(vector<vector<char>>& board){
        int row=board.size(),col=board[0].size();
        for(int i=0;i<row;i++){
            bool testrow[10],testcol[10];
            for(int t=0;t<10;t++){
                testrow[t]=testcol[t]=false;
            }
            for(int j=0;j<col;j++){
                if(board[i][j]!='.'){
                    if(testrow[board[i][j]-'0']) return false;
                    testrow[board[i][j]-'0']=true;
                }
                if(board[j][i]!='.'){
                    if(testcol[board[j][i]-'0']) return false;
                    testcol[board[j][i]-'0']=true;
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                bool testgrid[10];
                for(int t=0;t<10;t++){
                    testgrid[t]=false;
                }
                for(int m=i*3;m<i*3+3;m++){
                    for(int n=j*3;n<j*3+3;n++){
                        if(board[m][n]!='.'){   
                            if(testgrid[board[m][n]-'0']) return false;
                            testgrid[board[m][n]-'0']=true;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};