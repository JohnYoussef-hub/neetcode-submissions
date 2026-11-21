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
    int count = 0;

   public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        helper(root, root->val);
        return count;
    }

    void helper(TreeNode* root, int parent_val) {
        if (!root) return;

        if (root->val >= parent_val) count++;
        parent_val = max(parent_val, root->val);

        helper(root->left, parent_val);
        helper(root->right, parent_val);
    }
};
