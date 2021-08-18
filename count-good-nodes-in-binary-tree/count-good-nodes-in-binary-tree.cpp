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
    int sumNodes(TreeNode* root, int m) {
        int sum = 0;
        int max = m;
        if (root->val >= m) {
            sum += 1;
            max = root->val;
        }
        if (root->left)
            sum += sumNodes(root->left, max);
        if (root->right)
            sum += sumNodes(root->right, max);
        return sum;
    }
    int goodNodes(TreeNode* root) {
        return sumNodes(root, INT_MIN);
    }
};