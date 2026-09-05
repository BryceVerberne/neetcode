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
private:
    vector<int> m_solution;
    
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }

        dfs(node->left);
        dfs(node->right);
        m_solution.emplace_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return m_solution;
    }
};