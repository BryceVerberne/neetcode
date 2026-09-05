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
class BSTIterator {
private:
    TreeNode* m_it;
    stack<TreeNode*> m_callStack;

public:
    BSTIterator(TreeNode* root) : m_it(root) {}
    
    int next() {
        int res = 0;
        while (m_it || !m_callStack.empty()) {
            if (m_it) {
                m_callStack.push(m_it);
                m_it = m_it->left;
            }
            else {
                TreeNode* top = m_callStack.top();
                m_it = top;
                res = top->val;
                m_callStack.pop();
                m_it = m_it->right;
                break;
            }
        }

        return res;
    }
    
    bool hasNext() {
        return m_it || !m_callStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */