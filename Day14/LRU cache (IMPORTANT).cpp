class LRUCache {
    
public:
    class node{
        public:
        node* next;
        node* prev;
        int val;
        int key;
        public:
        node(int _key,int _val){
            key = _key;
            val = _val;
            
            
        }
    };
    
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int,node*> map;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    
    
    void addNode(node* newNode){
        
       node* nextNode = head->next;
        newNode->next = nextNode;
        newNode->prev = head;
        
        head->next = newNode;
        nextNode->prev = newNode;      
        
    }
    
    void deleteNode(node* delNode){
        
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            node* existingNode = map[key];
            int val = existingNode->val;
            map.erase(key);
            deleteNode(existingNode);
            addNode(new node(key,val));
            map[key] = head->next;
            return val;
            
        }
        return -1;
        
        
        
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            node* existingNode = map[key];
            map.erase(key);
            deleteNode(existingNode);
            
        }
        if(map.size()==cap) {
            map.erase(tail->prev->key);;
            deleteNode(tail->prev);            
            
        }
        addNode(new node(key,value));
        map[key] = head->next;
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */