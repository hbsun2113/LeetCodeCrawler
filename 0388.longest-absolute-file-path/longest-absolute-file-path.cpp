class Solution {
public:
    // 注意getline(sin, part)和sin>>part是有区别的
    // cin>>与getline的工作方式，流提取运算符根据它后面的变量类型读取数据，从非空白符号开始，遇到Enter、Space、Tab键时结束。getline函数从istream中读取一行数据，当遇到“\n”时结束返回。
    // https://blog.csdn.net/u011421608/article/details/44591579
    // 这题仔细观察不难，因为subdir1和subdir2其实是有顺序的，在遍历到subdir2时可以覆盖subdir1
    int lengthLongestPath(string input) {
        istringstream sin(input); 
        unordered_map<int,int> um;
        string part;
        int res=0;
        while(getline(sin, part)){
            int level=part.find_last_of('\t')+1;
            int len=part.size()-level;
            if(part.find('.')!=string::npos){
                res=max(res,um[level]+len);
            }
            else{
                um[level+1]=um[level]+len+1; // 文件夹的长度是为文件服务的。这个1应该是指/吧？
            }
        }
        return res;
    }
    
// 这个解法没有看，注意\t是一个字符 
int lengthLongestPath2(string input) {

    vector<int> dirs(256, 0);
    int res = 0;
    input.push_back('\n');
    
    for (int i = 0, level = 0, len = 0, isFile = 0; i < input.size(); i++) {
        switch (input[i]) {
            case '\n': level = 0; len = 0; isFile = 0; break;
            case '\t': level++; break;
            case '.' : isFile = 1;
            default:
                len++;
                dirs[level] = len;
                if (isFile) res = max(res, accumulate(dirs.begin(), dirs.begin() + level + 1, 0) + level);
        }
    }
    
    return res;
}
    
};