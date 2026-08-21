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
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0];
    }

private:
    vector<int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {1,0};
        }

        vector<int> left = dfs(root->left), right = dfs(root->right);
        bool balanced = left[0] && right[0] && (abs(left[1] - right[1]) <= 1);

        return {balanced, 1 + max(left[1], right[1])};
    }
};

/* Brute Force:
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int left = getHeight(root->left), right = getHeight(root->right);

        if (abs(left - right) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = getHeight(root->left), right = getHeight(root->right);

        return 1 + max(left, right);
    }
};

*/
