/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    int lp = minDepth(root->left);
    int rp = minDepth(root->right);
    if(lp == 0 || rp == 0)
    {
        return 1+fmax(lp,rp);
    }
    return 1+fmin(lp,rp);
}