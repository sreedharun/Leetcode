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
    vector<int> lvlo(TreeNode* root){
        if(root==nullptr){
            return {};
        }
        vector<int> v1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* t=q.front();
                q.pop();
                if(i==s-1){v1.push_back(t->val);}
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                if(t->right!=nullptr){
                    q.push(t->right);
                }
            }
        }
        return v1;
    }
    vector<int> rightSideView(TreeNode* root) {
        return lvlo(root);
    }
};