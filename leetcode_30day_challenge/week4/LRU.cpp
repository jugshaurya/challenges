class LRUCache{   
	struct Node{
	  Node* next;
	  Node* prev;
	  int value;
	  int key;
	  Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
	  Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
	};
	map<int,Node*>mp; 
	int cp;  
	Node* tail; 
	Node* head; 
public:
    LRUCache(int capacity) {
        cp = capacity;
        mp.clear();
        head=NULL;
        tail=NULL;
    }
    void insertNode(Node* node){
        if (!head){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
    }
    void rmNode(Node* node){
        if (node==head){
            head = head->next;
            if (head){head->prev = NULL;}
        }else{
            if (node==tail){
                tail =tail->prev;
                tail->next = NULL;
            }else{
                node->next->prev = node->prev;
                node->prev->next = node->next;
            }
        }
    }
    void moveNode(Node* node){
        if (tail==node){
            return;
        }else{
            if (node==head){
                node->next->prev = NULL;
                head = node->next;
                tail->next = node;
                node->prev = tail;
                tail=tail->next;
            }else{
                node->prev->next = node->next;
                node->next->prev = node->prev;
                tail->next = node;
                node->prev = tail;
                tail=tail->next;
            }
        }
    }
    int get(int key) {
        if (mp.find(key)==mp.end()){
            return -1;
        }else{
            Node *tmp = mp[key];
            moveNode(tmp);
            return mp[key]->value;
        }
    }
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()){
            moveNode(mp[key]);
            mp[key]->value = value;
        }else{
            if (mp.size()==cp){
                mp.erase(head->key);
                rmNode(head);
            }
            Node * node = new Node(key,value);
            mp[key] = node;
            insertNode(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// will require a queue and a map


// Algo

	// push => if capacity is not full then add element into queue and map
			// else pop queue front and remove that from map as well and then push to queue and map

	// pop =>  