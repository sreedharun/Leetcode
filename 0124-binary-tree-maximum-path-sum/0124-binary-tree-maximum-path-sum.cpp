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
    int maxSum=INT_MIN;
    int value(TreeNode* root){
          if(root==nullptr){
            return 0;
          }
          int left=max(value(root->left),0);
          int right=max(value(root->right),0);
          maxSum=max(maxSum,left+right+root->val);
          return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxSum=root->val;
        value(root);
        return maxSum;
    }
};