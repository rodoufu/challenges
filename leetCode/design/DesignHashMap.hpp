//https://leetcode.com/problems/design-hashmap/
class MyHashMap {
private:
    int size;
    vector<vector<tuple<int, int> > > values;

    inline int hash(int index, int max) {
        return index % max;
        //return (index * 2654435761 % (2 << 31) % max);
    }
    
    inline void print() {
        printf("{");
        for (int i = 0; i < size; ++i) {
            auto actual = values[i];
            if (actual.size()) {
                printf("%d: [", i);
                for (auto &x : actual) {
                    printf("%d:%d, ", std::get<0>(x), std::get<1>(x));
                }
                printf("],\n");
            }
        }
        printf("}\n");
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        size = 1000;
        for (int i = 0; i < size; ++i) {
            values.push_back(vector<tuple<int, int> >());
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &actual = values[hash(key, size)];
        bool found = false;
        auto actual_size = actual.size();
        //printf("put(%d, %d)\n", key, value);
        for (int i = 0; i < actual_size && !found; ++i) {
            //printf("put 1\n");
            if (std::get<0>(actual[i]) == key) {
                //printf("put 1.1\n");
                actual[i] = make_tuple(key, value);
                found = true;
            }
        }
        //printf("put 2\n");
        if (!found) {
            //printf("put 2.1\n");
            actual.push_back(make_tuple(key, value));
        }
        //print();
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        //printf("get(%d)\n", key);
        auto &actual = values[hash(key, size)];
        auto actual_size = actual.size();
        for (int i = 0; i < actual_size; ++i) {
            if (std::get<0>(actual[i]) == key) {
                //print();
                return std::get<1>(actual[i]);
            }
        }
        //print();
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        //printf("remove(%d)\n", key);
        auto &actual = values[hash(key, size)];
        for (auto it = actual.begin(); it != actual.end(); ++it) {
            if (std::get<0>(*it) == key) {
                actual.erase(it);
                break;
            }
        }
        //print();
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
