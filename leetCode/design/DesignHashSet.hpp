// https://leetcode.com/problems/design-hashset/
class MyHashSet {
private:
    vector<vector<int> > values;
    int size = 1000;
    
    inline int hash(int index, int size) {
        return index % size;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        for (int i = 0; i < size; ++i) {
            values.push_back(vector<int>());
        }
    }
    
    void add(int key) {
        auto &actual = values[hash(key, size)];
        for (auto &x : actual) {
            if (x == key) {
                return;
            }
        }
        actual.push_back(key);
    }
    
    void remove(int key) {
        auto &actual = values[hash(key, size)];
        for (auto it = actual.begin(); it != actual.end(); ++it) {
            if (*it == key) {
                actual.erase(it);
                break;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto &actual = values[hash(key, size)];
        for (auto &x : actual) {
            if (x == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
