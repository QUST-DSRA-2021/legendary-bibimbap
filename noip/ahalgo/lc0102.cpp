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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> res;
        if (root != nullptr) {
            queue <TreeNode *> que;
            que.push(root);
            while (!que.empty()) {
                int curlen = que.size();
                res.push_back(vector <int> ());
                for (int k = 0; k != curlen; ++k) {
                    auto curnode = que.front();
                    que.pop();
                    res.back().push_back(node->val);
                    if (curnode->left != nullptr)
                        que.push(curnode->left);
                    if (curnode->right != nullptr)
                        que.push(curnode->right);
                }
            }
        }
        return res;
    }
};
