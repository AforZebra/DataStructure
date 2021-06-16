// https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/536

bool checkSymmetry(TreeNode *A, TreeNode *B){
    if(!A && B || A && !B)return false;
    else if(!A && !B)return true;
    if(A->val != B->val)return false;
    return checkSymmetry(A->left, B->right) && checkSymmetry(A->right, B->left);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return checkSymmetry(root->left, root->right);
    }
};
