// https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/943/

TreeNode *TreeUtil(vector<int>inorder, int xi,int yi, vector<int>preorder,int xp,int yp){
    if(xi > yi || xp > yp)return nullptr;
    int temp = -1;
    TreeNode *node = new TreeNode(preorder[xp]);
    while(node->val != inorder[++temp]);
    node->left = TreeUtil(inorder, xi, temp-1,preorder, xp + 1, temp-xi+xp);
    node->right = TreeUtil(inorder, temp+1, yi,preorder, temp-xi+xp+1, yp);
    return node;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return TreeUtil(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1);
    }
};
