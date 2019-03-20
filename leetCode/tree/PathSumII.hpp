// https://leetcode.com/problems/path-sum-ii
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
    vector<tuple<int, vector<int> > > pathSum(TreeNode* root) {
        if (!root) {
            return vector<tuple<int, vector<int> > >();
        }
        auto resp(pathSum(root->left));
        {
            auto right = pathSum(root->right);
            resp.insert(resp.end(), right.begin(), right.end());
        }
        int size = resp.size();
        for (int i = 0; i < size; ++i) {
            auto val = get<0>(resp[i]);
            auto values = get<1>(resp[i]);
            values.push_back(root->val);
            resp[i] = make_tuple(val + root->val, values);
        }
        if (!size) {
            vector<int> values;
            values.push_back(root->val);
            resp.push_back(make_tuple(root->val, values));
        }
        
        return resp;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> resp;
        for (auto &x : pathSum(root)) {
            if (sum == get<0>(x)) {
                auto &values = get<1>(x);
                resp.push_back(vector<int>(values.rbegin(), values.rend()));
            }
        }
        
        return resp;
    }
};
