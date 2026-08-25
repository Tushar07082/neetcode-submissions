class Node {
    public: 
    int key;
    int val;
    Node * next;
    Node * prev;
    Node(int x, int y){
        key = x;
        val = y;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    Node* head, *tail;
    unordered_map<int, Node*> mp;
    int capacity;
public:
    LRUCache(int capacity) {
        head = nullptr;
        tail = nullptr;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        int value = mp[key]->val;
        remove(mp[key]);
        addToFront(key, value);
        return value;
    }
    
    void put(int key, int value) {
        //key already exists
        if(mp.find(key) != mp.end()){
            if(head == mp[key]) mp[key]->val = value;
            else{
                remove(mp[key]);
                addToFront(key, value);
            }
        }else if(mp.size() == capacity){
            removeTail();
            addToFront(key, value);
        }else{
            addToFront(key, value);
        }
        
    }

    void remove(Node *a){
        if(a->prev != nullptr){
            a->prev->next = a->next;
        }else{
            head = a->next;
        }
        if(a->next != nullptr){
            a->next->prev = a->prev;
        }else{
            tail = a->prev;
        }

        mp.erase(a->key);
        delete a;
    }

    void removeTail(){
        if(tail == nullptr) return;
        if(tail->prev == nullptr){
            head = nullptr;
            mp.erase(tail->key);
            delete(tail);
            tail = nullptr;
        }else{
            Node * prev = tail->prev;
            tail->prev->next = nullptr;
            mp.erase(tail->key);
            delete tail;
            tail = prev;
        }
    }

    void addToFront(int key, int value){
        Node* node = new Node(key, value);

        node->next = head;

        if (head != nullptr)
            head->prev = node;
        else
            tail = node;

        head = node;
        mp[key] = node;

    }
};
