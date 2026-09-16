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
    vector<vector<int>> lvlo(TreeNode* root){
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> rs;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> v1;
            for(int i=0;i<s;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                if(t->right!=nullptr){
                    q.push(t->right);
                }
                v1.push_back(t->val);
            }
            rs.push_back(v1);
        }
        return rs;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans=lvlo(root);
        vector<int> rs;
        for(int i=0;i<ans.size();i++){
            rs.push_back(ans[i][ans[i].size()-1]);
        }
        return rs;
    }
};