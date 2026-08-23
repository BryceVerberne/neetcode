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
        if (root == nullptr) {
            return vector<vector<int>>();
        }

        vector<vector<int>> list;
        queue<TreeNode*> q;

        // Start off the data structures
        list.push_back(vector<int>());
        list[0].push_back(root->val);
        q.push(root);

        // Begin iterating through the queue
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            ++level;

            for (int i = 0; i < size; ++i) {
                TreeNode* front = q.front();

                if (front->left != nullptr) {
                    if (list.size() <= level) list.push_back(vector<int>()); 

                    list[level].push_back(front->left->val);
                    q.push(front->left);
                }
                if (front->right != nullptr) {
                    if (list.size() <= level) list.push_back(vector<int>());

                    list[level].push_back(front->right->val);
                    q.push(front->right);
                }

                q.pop();
            }
        }

        return list;
    }
};
