// https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/942

TreeNode *Tree(vector<int> inorder,int xi,int yi, vector<int> postorder,int xp,int yp){
    if(xi > yi || xp > yp)return nullptr;
    TreeNode *node = new TreeNode(postorder[yp]);
    int temp = -1;
    while(node->val != inorder[++temp]);
    node->left = Tree(inorder, xi, temp-1, postorder, xp, temp - xi + xp -1);
    node->right = Tree(inorder, temp + 1, yi, postorder, temp - xi + xp, yp - 1);
    return node;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Tree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
