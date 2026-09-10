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
    int count=0;
    int c,sum;
    vector<int> tra(TreeNode* root){
        if(root==nullptr){return {};}
        tra(root->left);
        sum+=root->val;
        c++;
        tra(root->right);
        return {c,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        c=0,sum=0;
        vector<int> ans=tra(root);
        if(root->val==(ans[1]/ans[0])){
            count++;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return count;
        // if(ans[0]==(ans[1]/ans[0])){
        //     count++;
        // }
        // averageOfSubtree(root->left);
        // averageOfSubtree(root->right);
        // return count;
    }
};