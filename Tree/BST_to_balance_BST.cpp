// https://leetcode.com/problems/balance-a-binary-search-tree

class Solution {
public:
    void inorder(TreeNode *root, vector<TreeNode*>&v){
        if(!root)return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    
    TreeNode *buildTree(int s, int e, vector<TreeNode*>&v){
        if(s > e)return NULL;
        if(s == e){
            v[s]->right = NULL;
            v[s]->left = NULL;
            return v[s];
        }
        int mid = s + (e-s)/2;
        v[mid]->left = buildTree(s,mid-1,v);
        v[mid]->right = buildTree(mid+1,e,v);
        return v[mid];
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>v;
        inorder(root, v);
        return buildTree(0, v.size()-1, v);
    }
};
