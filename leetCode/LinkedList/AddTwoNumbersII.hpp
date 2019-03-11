//https://leetcode.com/problems/add-two-numbers-ii
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        auto temp = l1;
        while (temp) {
            v1.push_back(temp->val);
            temp = temp->next;
        }
        
        temp = l2;
        while (temp) {
            v2.push_back(temp->val);
            temp = temp->next;
        }
        
        if (v1.size() < v2.size()) {
            swap(v1, v2);
        }
        
        for (auto it1 = v1.rbegin(), it2 = v2.rbegin(); it1 != v1.rend() && it2 != v2.rend(); ++it1, ++it2) {
            *it1 += *it2;
        }
        
        int size = v1.size();
        for (int i = size - 1; i > 0; --i) {
            v1[i - 1] += v1[i] / 10;
            v1[i] %= 10;
        }
        temp = new ListNode(0);
        int vaiUm = 0;
        for (auto it1 = v1.rbegin(); it1 != v1.rend(); ++it1) {
            temp->val = *it1 + vaiUm;
            vaiUm = temp->val / 10;
            temp->val %= 10;

            auto aux = new ListNode(0);
            aux->next = temp;
            temp = aux;
        }
        if (vaiUm) {
            temp->val = vaiUm;
        } else {
            auto aux = temp;
            temp = temp->next;
            delete aux;
        }
        
        return temp;
    }
};
