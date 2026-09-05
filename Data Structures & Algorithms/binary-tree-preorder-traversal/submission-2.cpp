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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> solution;
        stack<TreeNode*> dfsStack;
    
        TreeNode* curr = root;
        while (curr || !dfsStack.empty()) {
            if (curr) {
                if (curr->right) {
                    dfsStack.push(curr->right);
                }
                solution.emplace_back(curr->val);
                curr = curr->left;
            }
            else {
                curr = dfsStack.top();
                dfsStack.pop();
            }
        }

        return solution;
    }
};

/*
Recursive Solution:
class Solution {
private:
    vector<int> m_solution;

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }

        m_solution.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return m_solution;
    }
};
*/