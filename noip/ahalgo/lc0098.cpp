/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool judgebst(TreeNode *root, long long minval=LONG_MIN, long long maxval=LONG_MAX) {
        return (root != nullptr) ? ((minval < root->val && root->val < maxval) ? (judgebst(root->left, minval, root->val) && judgebst(root->right, root->val, maxval)) : (false)) : (true);
    }
    bool isValidBST(TreeNode* root) {
        return judgebst(root);
    }
};
