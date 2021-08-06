// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* call(vector<int>arr, int &idx, int inorderNode){
        if(idx >= arr.size() || arr[idx] > inorderNode)return NULL;
        TreeNode* newNode = new TreeNode(arr[idx++]);
        newNode->left = call(arr, idx, newNode->val);
        newNode->right = call(arr, idx, inorderNode);
        return newNode;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return call(preorder, idx, INT_MAX);
    }
};
