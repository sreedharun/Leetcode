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
    TreeNode* bst(vector<int>& nums,TreeNode*& root,int l,int h){
        if(l>h){return nullptr;}
        int m=l+((h-l)>>1);
        root=new TreeNode(nums[m]);
        bst(nums,root->left,l,m-1);
        bst(nums,root->right,m+1,h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        TreeNode* root;
        return bst(nums,root,0,n-1);
    }
};