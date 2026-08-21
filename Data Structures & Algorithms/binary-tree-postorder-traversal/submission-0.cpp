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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        traversal(root, list);

        return list;
    }

private:
    void traversal(TreeNode* root, vector<int>& list) {
        if (root == nullptr) {
            return;
        }

        traversal(root->left, list);
        traversal(root->right, list);
        list.push_back(root->val);
    }
};