// https://leetcode.com/problems/diameter-of-binary-tree/

int call(TreeNode *root, int &ans){
    if(!root)return 0;
    int l = call(root->left, ans);
    int r = call(root->right, ans);
    ans = max(l+r+1, ans);
    return max(l,r)+1;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int ans = 0;
        call(root, ans);
        return ans-1;
    }
};
