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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> rs;
        queue<TreeNode*> q;
        q.push(root);
        int z=0;
        while(!q.empty()){
            int s=q.size();
            vector<int> in;
            for(int i=0;i<s;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                if(t->right!=nullptr){
                    q.push(t->right);
                }
                in.push_back(t->val);
            }
            z++;
            if(z%2!=0){
                rs.push_back(in);
            }else{
                reverse(in.begin(),in.end());
                rs.push_back(in);
            }
        }
        return rs;
    }
};