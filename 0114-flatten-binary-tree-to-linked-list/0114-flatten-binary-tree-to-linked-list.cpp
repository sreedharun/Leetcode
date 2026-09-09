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
    vector<int> pre;
    void preorder(TreeNode* root){
        if(root==nullptr){return;}
        pre.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root){
        preorder(root);
        if(root==nullptr){return;}
        root->left=nullptr;
        root->right=nullptr;
        int i=1,n=pre.size();
        while(i<n){
            root->right=new TreeNode(pre[i]);
            root=root->right;
            i++;
        }
    }
};