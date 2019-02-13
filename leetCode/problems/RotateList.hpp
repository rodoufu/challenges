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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }
        
        if (k) {
            vector<int> resp;
            auto it = head;
            while (it) {
                resp.push_back(it->val);
                it = it->next;
            }
            int size = resp.size();
            std::rotate(resp.begin(), resp.begin() + (size - k % size), resp.end());
            it = head;
            auto itResp = resp.begin();
            while (it) {
                it->val = *itResp;
                ++itResp;
                it = it->next;
            }
        }
        return head;
    }
};
