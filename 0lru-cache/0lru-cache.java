class LRUCache {
    LinkedHashMap<Integer,Integer> cache;
    int capacity;

    public LRUCache(int capacity) {
        cache = new LinkedHashMap<>();
        this.capacity=capacity;
        
    }
    
    public int get(int key) {
        
        if(cache.containsKey(key)) {
            int val = cache.get(key);
            cache.remove(key);
            cache.put(key, val);
            return cache.get(key);
        }
        
        return -1;
    }
    
    public void put(int key, int value) {
        
        if(cache.containsKey(key)) {
            cache.remove(key);
            cache.put(key, value);
        }
        else {
            if(cache.size()>=capacity) {
                int oldKey = cache.keySet().iterator().next();
                cache.remove(oldKey);
                cache.put(key, value);
            } else {
                cache.put(key, value);
            }
        }
        
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */