struct Node{
    Node *links[26];
    bool flag = false;
    int cntPrefix =0;
    int cntEnd =0;
    
    bool containsKey(char ch){
        return links[ch - 'a'];
    }
    
    void put(Node* node,char ch){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void increasePrefix(bool isIncrease){
        if(isIncrease)cntPrefix++;
        else cntPrefix--;
    }
    void increaseEnd(bool isIncrease){
        if(isIncrease)cntEnd++;
        else cntEnd--;
    }
    
    int getEnd(){
        return cntEnd;
    }
    int getPrefix(){
        return cntPrefix;;
    }
};

class Trie{
    private: Node* root;
 
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(new Node(),word[i]);
            }            
            node = node->get(word[i]);
            node->increasePrefix(true);
        }
        
        node->increaseEnd(true);
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }            
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }            
            node = node->get(word[i]);
        }
        return node->getPrefix();
        
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return ;
            }            
            node = node->get(word[i]);
            node->increasePrefix(false);
        }
        
        node->increaseEnd(false);
   
    }
};










// 3
// 9
// insert fdfsr
// insert dfweafee
// insert ergerfsd
// countWordsEqualTo fdfsr
// countWordsStartingWith fdfsr
// countWordsStartingWith er
// insert sdfscds
// insert wrwesadasd
// countWordsEqualTo sdfscds
// 6
// insert aaa
// insert bbb
// insert ccc
// countWordsEqualTo bbb
// erase ccc
// countWordsStartingWith aa
// 6
// insert dsdew
// insert dqwd
// insert edasadsad
// countWordsEqualTo dsdew
// countWordsStartingWith dsad
// countWordsEqualTo dasd

