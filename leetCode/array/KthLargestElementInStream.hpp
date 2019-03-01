//https://leetcode.com/problems/kth-largest-element-in-a-stream/
#define PRINT_ALL(X, Y, Z) {\
        printf(Y); \
        bool __rool = false; \
        for (auto ___it = (X).begin(); ___it != (X).end(); ++___it) { \
            if (__rool) printf(", "); \
            printf("%d", *___it); \
            __rool = true; \
        } \
        printf(Z); \
    }

class KthLargest {
private:
    int k;
    vector<int> values;

    void sortV(int index) {
        while (index) {
            if (values[index - 1] < values[index]) {
                swap(values[index - 1], values[index]);
                --index;
            } else {
                break;
            }
        }
    }

    void insert(int x) {
        int size = values.size();
        if (size <= k) {
            values.push_back(x);
            sortV(size);
        } else {
            values[k] = x;
            sortV(k);
        }
    }

public:
    KthLargest(int _k, vector<int> nums) : k(_k) {
        for (auto it : nums) {
            insert(it);
        }
        //PRINT_ALL(values, "KthLargest\n", "\n");
    }
    
    int add(int val) {
        insert(val);
        int size = values.size();
        int index = max(0, size <= k ? size - 1 : size - 2);
        //printf("%d, %d -> ", val, values[index]);
        //PRINT_ALL(values, "add\n", "\n");
        return values[index];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
