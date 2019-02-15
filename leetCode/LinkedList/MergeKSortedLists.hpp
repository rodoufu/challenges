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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) {
            return nullptr;
        }
        bool allEmpty = true;
        for (int i = 0; i < size && allEmpty; ++i) {
            allEmpty &= lists[i] == nullptr;
        }
        if (allEmpty) {
            return nullptr;
        }
        
        auto resp = new ListNode(0);
        auto itResp = resp;
        
        bool keepGoing = true;
        while (keepGoing) {
            auto itMin = lists.end();
            keepGoing = false;
            itResp->next = new ListNode(0);
            for (auto it = lists.begin(); it != lists.end(); ++it) {
                if ((itMin == lists.end() && *it) 
                    || (*it && itMin != lists.end()  && (*it)->val < (*itMin)->val)) {
                    itMin = it;
                    keepGoing = true;
                }
            }
            if (keepGoing) {
                itResp->val = (*itMin)->val;
                *itMin = (*itMin)->next;
                allEmpty = true;
                for (int i = 0; i < size && allEmpty; ++i) {
                    allEmpty &= lists[i] == nullptr;
                }
                if (!allEmpty) {
                    itResp = itResp->next;
                } else {
                    keepGoing = false;
                }
            }
        }
        
        delete itResp->next;
        itResp->next = nullptr;
        return resp;
    }
};
