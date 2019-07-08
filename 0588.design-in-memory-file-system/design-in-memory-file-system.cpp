// 完全自己写的，没有看其他人，将近耗费了一下午
// 下次可以按照https://leetcode.com/problems/design-in-memory-file-system/discuss/103331/Java-Solution-File-class 进行重构：
// 1. 将next数组替换成map,可以减少遍历时间: 已经更改了，提速效果很明显
// 2. mkdir 中不必先找到已知路径后，再新建。可以一边新建一边往下走

class Node{
public:    
    bool isdirectory=true; // 标记是文件还是目录
    unordered_map<string, Node*> next; // 如果是目录，那肯定还有各种儿子
    string name=""; // 本节点的名字，自从改为map,这个字段就没有用了
    string content; // 如果是文件，本节点的内容
    Node(string _name):name(_name){} 
};

class FileSystem {
private:
    vector<string> vec; // 分别保存path的各个字段
    Node *root;
    
    void path2vec(string &path){
        vec.clear();
        vec.reserve(100);
        path = path.substr(1); // 如果不把第一个"/"去掉，则vec中第一个元素为""
        istringstream ins(path);
        while(getline(ins,path,'/')) vec.push_back(path);
    }
    
    
public:
    FileSystem() {
        root=new Node("");
    }
    
    vector<string> ls(string path) {
        // cout<<"ls start"<<endl;
        path2vec(path);
        
        // 因为是ls，所以路径肯定存在，能一直走到根节点
        int i=0;
        auto cur=root;
        while(i<vec.size()) cur=cur->next[vec[i++]];

        // 判断最后一个节点是目录还是文件
        if(cur->isdirectory==false){
            // cout<<"ls succ1"<<endl;
            return {vec.back()};
        } 
        else{
            vector<string> res;
            for(const auto &n:cur->next) res.push_back(n.first);
            sort(res.begin(),res.end());
            // cout<<"ls succ2"<<endl;
            return res;
        }
    }
    
    // isd用来设置最后一个节点到底是目录还是文件：
    // 如果直接调用mkdir，就是目录。所以默认为目录
    // 如果是addContentToFile,最后一个节点就是文件
    // 注意：因为我们要改变指针的指向，所以要用指针的指针
    // https://blog.csdn.net/laojing123/article/details/6544275
    void mkdir(string path, bool isd=true, Node** res=nullptr) {
        // cout<<"mkdir start"<<" "<<path<<endl;
        path2vec(path);
        
        // 因为可能父目录不存在，所以可能中途就断掉
        int i=0;
        auto cur=root;
        while(i<vec.size()){
            if(cur->next.find(vec[i])==cur->next.end()) cur->next[vec[i]]=new Node("");
            cur=cur->next[vec[i++]];
        }
        
        // 按照真实的需求，设置到底是目录还是文件
        cur->isdirectory=isd;
        if(res!=nullptr) *res=cur;
        // cout<<"mkdir suc"<<endl;
    }
    
    void addContentToFile(string filePath, string content) {
        // cout<<"addContentToFile start"<<endl;
        Node *cur; // 指向尾节点
        mkdir(filePath,false,&cur);
        cur->content+=content;
        // cout<<"addContentToFile suc"<<endl;
    }
    
    string readContentFromFile(string filePath) {
        // cout<<"readContentFromFile start"<<endl;
        path2vec(filePath);
        
        int i=0;
        auto cur=root;
        while(i<vec.size()) cur=cur->next[vec[i++]];
        // cout<<"readContentFromFile suc"<<endl;
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */