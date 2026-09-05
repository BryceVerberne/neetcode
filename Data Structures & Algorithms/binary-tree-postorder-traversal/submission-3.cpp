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
        vector<int> solution;
        stack<pair<TreeNode*,bool>> callStack;

        callStack.push({root,false});
        TreeNode* curr = root;
        while (!callStack.empty()) {
            bool visit = callStack.top().second;
            curr = callStack.top().first;
            callStack.pop();
            
            if (curr) {
                if (visit) {
                    solution.emplace_back(curr->val);
                }
                else {
                    callStack.push({curr,true});
                    callStack.push({curr->right,false});
                    callStack.push({curr->left,false});
                }
            }
        }

        return solution;
    }
};


/*
Recursive Solution:
```
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
```
*/