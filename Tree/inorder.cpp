// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<pair<TreeNode*,int>>s;
        if(!root)return v;
        s.push({root,0});
        while(!s.empty()){
            pair<TreeNode*, int> top = s.top();
            if(top.first->left != NULL && top.second == 0){
                s.top().second = top.second + 1;
                s.push({top.first->left,0});
            }
            else{
                v.push_back(top.first->val);
                s.pop();
                if(top.first->right != NULL){
                    s.push({top.first->right,0});
                }
            }
        }
        return v;
    }
};

// Optimized Solution

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int>v;
        stack<TreeNode*>s;
        if(!A)return v;
        TreeNode *curr = A;
        while(!s.empty() || curr){
            if(curr){
                s.push(curr);
                curr = curr->left;
            }
            else{
                v.push_back(s.top()->val);
                curr = s.top()->right;
                s.pop();
            }
        }
        return v;
}
