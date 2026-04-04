1class Solution {
2public:
3    int minDepth(TreeNode* root) {
4        if (!root) return 0;
5
6        // If one child is NULL, go to the other
7        if (!root->left) return 1 + minDepth(root->right);
8        if (!root->right) return 1 + minDepth(root->left);
9
10        return 1 + min(minDepth(root->left), minDepth(root->right));
11    }
12};