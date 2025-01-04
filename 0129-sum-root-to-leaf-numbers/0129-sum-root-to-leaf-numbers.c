/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum =0;
void pathSum(struct TreeNode* root,int rs,int *psum){
    if(root == NULL) return;
    if(!root -> left && !root -> right)
     *psum = *psum+rs*10+root->val;
    pathSum(root->left,rs*10+root->val,psum);
    pathSum(root->right,rs*10+root->val,psum);
}
int sumNumbers(struct TreeNode* root) {
    sum =0;
    pathSum(root,0,&sum);
    return sum;
}