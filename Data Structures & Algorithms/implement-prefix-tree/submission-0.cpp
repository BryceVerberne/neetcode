struct TreeNode {
    unordered_map<char,TreeNode*> children;
    bool word;

    TreeNode() : word(false) {}
    TreeNode(bool word) : word(word) {}
};

class PrefixTree {
private:
    TreeNode* root;

public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* curr = root;

        for (const char letter : word) {
            if (!curr->children.contains(letter)) {
                curr->children[letter] = new TreeNode();
            }

            curr = curr->children[letter];
        }

        curr->word = true;
    }
    
    bool search(string word) {
        TreeNode* curr = root;

        for (const char letter : word) {
            if (!curr->children.contains(letter)) {
                return false;
            }
            curr = curr->children[letter];
        }

        return curr->word;
    }
    
    bool startsWith(string prefix) {
        TreeNode* curr = root;

        for (const char letter : prefix) {
            if (!curr->children.contains(letter)) {
                return false;
            }
            curr = curr->children[letter];
        }

        return true;
    }
};
