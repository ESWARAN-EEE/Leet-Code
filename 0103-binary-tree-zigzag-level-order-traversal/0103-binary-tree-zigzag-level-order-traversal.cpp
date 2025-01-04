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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>res;
      if(root == NULL) return res;
      queue<TreeNode *> q;
      q.push(root);
      int flag = 1;
      while(!q.empty()){
            vector<int>v;
            for(int cnt = q.size();cnt;cnt--){
            TreeNode* curr = q.front();
            q.pop();
            v.push_back(curr -> val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            }
            if(flag ==0) reverse(v.begin(),v.end());
            flag = !flag;
            res.push_back(v);
      }
      return res; 
      }
};