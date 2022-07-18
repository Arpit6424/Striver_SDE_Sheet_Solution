struct Node{
   int key,val, cnt;
    Node* next;
    Node* prev;
    Node(int _key , int _val){
        val = _val;
        key = _key;
        cnt = 1;
    }
};

struct List{
    
    int size;
    Node *head;
    Node *tail;
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node *newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }
    
    void deleteNode(Node *delNode){
        
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        size--;
    }
};

class LFUCache {
    map<int,Node*> keyNode;
    map<int,List*> freqlistMap;
    int maxSize;
    int curSize;
    int minFreq;
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        curSize = 0;
        minFreq = 0;
    }
    
    
    void updateFreqlistMap(Node *node){
        
        keyNode.erase(node->key);
        freqlistMap[node->cnt]->deleteNode(node);
        
        if(node->cnt == minFreq && freqlistMap[node->cnt]->size==0){
            minFreq++;
        }
        
        List* nextHigherFreqList = new List();
        if(freqlistMap.find(node->cnt+1) != freqlistMap.end()){
            nextHigherFreqList = freqlistMap[node->cnt+1];
        }
        
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqlistMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
        
        
        
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* resNode = keyNode[key];
            int val = resNode->val;
            updateFreqlistMap(resNode);
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        
        if(maxSize == 0)return ;      
      
            
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqlistMap(node);
        }
        else{
            if(curSize == maxSize){
               List* list = freqlistMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqlistMap[minFreq]->deleteNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqlistMap.find(minFreq) != freqlistMap.end()){
                listFreq = freqlistMap[minFreq];
            }
            Node* node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqlistMap[minFreq] = listFreq;

        }
        
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */