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
    int Msum=INT_MIN;
    int val(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left=max(val(root->left),0);
        int right=max(val(root->right),0);
        Msum=max(Msum,left+right+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        Msum=root->val;
        val(root);
        return Msum;
    }
};