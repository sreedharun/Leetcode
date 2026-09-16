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
    bool h(TreeNode* root,long long mx,long long mn){
        if(root==nullptr){
            return true;
        }
        if(root->val <= mn || root->val >=mx){
            return false;
        }
        return h(root->left,root->val,mn) && h(root->right,mx,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return h(root,LLONG_MAX,LLONG_MIN);
    }
};