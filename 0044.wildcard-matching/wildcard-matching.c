//https://leetcode.com/problems/wildcard-matching/discuss/17810/Linear-runtime-and-constant-space-solution
//这道题目还没有完全理解
bool isMatch(char* s, char* p) {
        char *ps=s;
        char *pp=p;
        char *fs=ps;
        char *fp=NULL;
        while(*ps){  //注意是*ps，不是ps
            printf("%c %c\n",*ps,*pp);
            if((*pp=='?') || (*ps==*pp)){
                pp++;
                ps++;
                continue;
            }
            
            if(*pp=='*'){
                fp=pp++;
                fs=ps;
                continue;
            }
            
            if(fp){
                pp=fp+1;
                ps=++fs;
                continue;
            }
            
            return false;
            
        }
        while(*pp=='*') pp++;
        
        return !(*pp);
}