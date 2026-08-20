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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        // Iterate down the tree
        TreeNode* node = root;
        while(node != nullptr) {
            if (val > node->val) {
                if (node->right == nullptr) {
                    node->right = new TreeNode(val);
                    break;
                }
                node = node->right;
            }
            else {
                if (node->left == nullptr) {
                    node->left = new TreeNode(val);
                    break;
                }
                node = node->left;
            }
        }

        return root;
    }
};

/* Recursive Solution
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }
    else { // val < root->val
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}
*/