// ?????isfile???https://leetcode.com/submissions/detail/267061945/
class Node{
public:
    unordered_map<string,Node*> um;
    int content;
    bool isfile=false;
};

class FileSystem {
public:
    Node* root=new Node();
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        string parent=string(path.begin(),path.begin()+path.rfind('/'));
        string filename=path.substr(path.rfind('/')+1);
        // cout<<parent<<" "<<filename<<" "<<value<<endl;
        istringstream ins(parent);
        string t;
        getline(ins,t,'/');
        auto cur=root;
        while(getline(ins,t,'/')){
            if(cur->um.find(t)==cur->um.end()) return false;
            cur=cur->um[t];
        }
        if(cur->um.find(filename)!=cur->um.end()) return false;
        cur->um[filename]=new Node();
        cur=cur->um[filename];
        cur->isfile=true;
        cur->content=value;
        return true;
    }
    
    int get(string path) {
        istringstream ins(path);
        string t;
        getline(ins,t,'/');
        auto cur=root;
        while(getline(ins,t,'/')){
            if(cur->um.find(t)==cur->um.end()) return -1;
            cur=cur->um[t];
        }
        if(!cur->isfile) return -1;
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */