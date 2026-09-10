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
    long long incR(TreeNode* root,long long sum){
        if(root==nullptr){
            return 0;
        }
        long long res=0;
        if(root->val==sum) res++;
        res+=incR(root->left,sum-root->val);
        res+=incR(root->right,sum-root->val);
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return 0;
        }
        return pathSum(root->left,targetSum)+incR(root,targetSum)+pathSum(root->right,targetSum);
    }
};