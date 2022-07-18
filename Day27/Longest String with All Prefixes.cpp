struct Node{
    Node *links[26];
    bool isTerminal = false;  
    
    bool iscontainsKey(char ch){
        return links[ch - 'a'];
    }    
    void put(char ch , Node* node){
        links[ch-'a'] = node;
    }    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        isTerminal = true;
    }    
    bool isEnd(){
        return isTerminal;
    }
};

class Trie{
    private: Node *root;
    
    public:
    Trie(){
        root = new Node();
    };
    
    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->iscontainsKey(word[i])){
                node->put(word[i],new Node());
            }            
            node = node->get(word[i]);            
        }        
        node->setEnd();        
    }
    
    bool checkIfAllPrefixExists(string &word){
        bool flag = true;
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->iscontainsKey(word[i])){
                return false;
            }
            else{
                node = node->get(word[i]);
                flag = node->isEnd() && flag;
            }
        }
        return flag;
    }
};


string completeString(int n, vector<string> &a){
    // Write your code here.
    
    Trie trie;
    for(auto it : a){
        trie.insert(it);
    }
    
    string longest ="";
    for(auto it : a){        
        if(trie.checkIfAllPrefixExists(it)){
            if(it.length() > longest.length()){
                longest = it;
            }
            else if(it.length() == longest.length() && it <longest){
                longest = it;
            }
        }
    }    
    if(longest == "")return "None";
    return longest;
}










