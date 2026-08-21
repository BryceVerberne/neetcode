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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {
            if (root->right == nullptr) {
                TreeNode* node = root->left;
                delete root;
                return node;
            }
            else if (root->left == nullptr) {
                TreeNode* node = root->right;
                delete root;
                return node;
            }
            else {
                int minNode = getMin(root->right);
                root->right = deleteNode(root->right, minNode);
                root->val = minNode;
            }
        }

        return root;
    }

private:
    int getMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }

        return root->val;
    }
};