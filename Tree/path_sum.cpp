// https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/537

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        if((targetSum - root->val) == 0 && !root->left && !root->right)return true;
        return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
    }
};
