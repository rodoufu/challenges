//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* sortedArrayToBST(std::vector<int>::iterator& from, std::vector<int>::iterator& to) {
        // if (from == to) {
            // return new TreeNode(*from);
        // }
        if (from == to || from > to) {
            return nullptr;
        }
        auto middle = from + (to - from) / 2;
        auto resp = new TreeNode(*middle);
        // auto middleLess = middle - 1;
        resp->left = sortedArrayToBST(from, middle);
        auto middlePlus = middle + 1;
        resp->right = sortedArrayToBST(middlePlus, to);
        return resp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int from, int to) {
        // printf("f:%d,t:%d", from, to);
        // if (from == to) {
            // return new TreeNode(*from);
        // }
        if (from == to || from > to) {
            // putchar('\n');
            return nullptr;
        }
        auto middle = from + (to - from) / 2;
        auto resp = new TreeNode(nums[middle]);
        // printf(",v:%d\n", resp->val);
        // auto middleLess = middle - 1;
        resp->left = sortedArrayToBST(nums, from, middle);
        auto middlePlus = middle + 1;
        resp->right = sortedArrayToBST(nums, middlePlus, to);
        return resp;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // auto from = nums.begin();
        // auto to = nums.end();
        // return sortedArrayToBST(from, to);
        return sortedArrayToBST(nums, 0, nums.size());
    }
};
