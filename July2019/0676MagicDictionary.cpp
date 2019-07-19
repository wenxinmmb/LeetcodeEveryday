// https://leetcode.com/problems/implement-magic-dictionary/
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    struct Node {
        int count = 0;
        unordered_map<char,Node*> nodes;
    };
    
    Node* root = NULL;
    MagicDictionary() {
        root = new Node();
    }
    ~MagicDictionary() {
        clearUp(root);
    }
    void clearUp(Node *curNode){
        if(curNode == NULL)
            return;
        
        for(auto en: curNode->nodes){
            clearUp(en.second);
        }
        
        delete curNode;
        return;
    }
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        
        Node* curNode;
        for(auto d:dict){
            curNode = root;
            for(auto e:d){
                if(curNode->nodes.find(e) == curNode->nodes.end()){
                    curNode->nodes[e] = new Node();
                }
                curNode = curNode->nodes[e];
            }
            curNode->count = 1;
            
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search_helper(string word,Node* root) {
        Node* curNode = root;
        for(auto a: word){
            if(curNode->nodes.find(a) == curNode->nodes.end())
                return false;
            curNode = curNode->nodes[a];
        }
        if(curNode->count == 1)
            return true;
        return false;
    }
    
    bool search(string word) {
        Node* curNode = root;
        Node* nxtNode;
        for(int i = 0; i < word.size(); i++){
            char a = word[i];
            if(!curNode)
                return false;
            bool found = false;
            for(auto e: curNode->nodes){
                if(e.first != a){
                    if(search_helper(word.substr(i+1),e.second))
                        return true;
                }
                else{
                    found = true;
                    nxtNode = e.second;
                }
            }
            if(found)
                curNode = nxtNode;
            else
                return false;
            if(i == word.size()-1)
                return false;
        }
        if(curNode->count == 1)
            return true;
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */