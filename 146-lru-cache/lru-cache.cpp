class LRUCache {
public:
    class Node {
        public:
            int key;
            int value;
            Node* next;
            Node* prev;
            Node(int k, int v) {
                key = k;
                value = v;
            }
    };

    void addNode(Node* node){
        Node* tempNext = head->next;
        node->next = tempNext;
        node->prev = head;
        head->next = node;
        tempNext->prev = node;
    }

    void deleteNode(Node* node){
        Node* tempNext = node->next;
        Node* tempPrev = node->prev;
        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;
    }

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* reqNode = mp[key];
            int val = reqNode->value;
            mp.erase(key);
            deleteNode(reqNode);
            addNode(reqNode);
            mp[key] = head->next;

            return val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }

        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */