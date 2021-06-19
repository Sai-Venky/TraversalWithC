// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    struct trail {
        trail *trails[10];
        int trailValue;
        bool endOfTrail;
        trail *next;
        trail *prev;
    };
    trail *end,  *root;
    trail* newTrail() {
        trail* newTrailNode = (trail *)malloc(sizeof(trail));
        for(int i=0; i<10; i++) {
            newTrailNode->trails[i] = NULL;
        }        
        newTrailNode->endOfTrail = false;
        newTrailNode->trailValue = -1;
        newTrailNode->next = NULL;
        newTrailNode->prev = NULL;
        return newTrailNode;
    }
    int capacity, current = 0;
    LRUCache(int ccapacity) {
        root = newTrail();
        end = root;
        capacity = ccapacity;  
    }
    
    void updateTrailLRU(trail *node) {
        if(end==node) return;
        if(node->endOfTrail == true) {
            node->prev->next = node->next; 
            node->next->prev = node->prev;
            node->prev = NULL;
            node->next = NULL;
       }
        end->next = node;
        node->prev = end;
        end = node;          
    }
 
    int get(int key) {
        trail *trailTrav = root;
        int trailTravKey = key;
        
        while(trailTravKey!=0) {
            int keyValue = trailTravKey%10;

            if(trailTrav->trails[keyValue] == NULL) return -1;
            trailTrav = trailTrav->trails[keyValue];
            trailTravKey = trailTravKey/ 10;
        }
  
        if(trailTrav->endOfTrail == true) {
            updateTrailLRU(trailTrav);
            return trailTrav->trailValue;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        trail *trailTrav = root;
        int trailTravKey = key;
        
        while(trailTravKey!=0) {
            int keyValue = trailTravKey%10;
            if(trailTrav->trails[keyValue] == NULL) {
                trailTrav->trails[keyValue] = newTrail();        
            }
            trailTrav = trailTrav->trails[keyValue];
            trailTravKey /= 10;
        }
        
        trailTrav->trailValue = value;
        
        
        updateTrailLRU(trailTrav);
        if(trailTrav->endOfTrail == false){

            current++;  
        } 
                  
        trailTrav->endOfTrail = true; 
        
        if(current>capacity) {
            root->next->endOfTrail = false;
            root->next->next->prev = root;
            root->next =  root->next->next;
            current-=1;
        }
        

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */