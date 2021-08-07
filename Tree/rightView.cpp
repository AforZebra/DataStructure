// https://leetcode.com/problems/binary-tree-right-side-view/submissions/

class Solution {
public:
    void call(TreeNode *root, int level, vector<int>&ans, int &newLevel){
        if(!root)return;
        if(level > newLevel){
            newLevel = level;
            ans.push_back(root->val);
        }
        call(root->right, level+1,ans,newLevel);
        call(root->left, level+1,ans,newLevel);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int newLevel = -1;
        call(root, 0, ans, newLevel);
        return ans;
    }
};
