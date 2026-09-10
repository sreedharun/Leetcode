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
    TreeNode* bst(vector<int>& nums,int l,int h){
        if(l>h){return nullptr;}
        int m=l+((h-l)>>1);
        TreeNode* root=new TreeNode(nums[m]);
        root->left=bst(nums,l,m-1);
        root->right=bst(nums,m+1,h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return bst(nums,0,n-1);
    }
};