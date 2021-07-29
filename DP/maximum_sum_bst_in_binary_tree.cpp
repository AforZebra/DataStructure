// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/submissions/

class Solution {
public:
   vector<int> call(TreeNode *root, int &ans, vector<int>v){
        if(!root){
            return {0, 1, INT_MAX, INT_MIN};
        }
        vector<int> l = call(root->left, ans,v);
        vector<int> r = call(root->right, ans,v);
        if(root->left && ((root->val <= root->left->val) || (root->val <= l[3]))){
            return {root->val, 0, INT_MIN, INT_MAX};
        }
        if(root->right && ((root->val >= root->right->val) || (root->val >= r[2]))){
            return {root->val, 0, INT_MIN, INT_MAX};
        }
        if(l[1] && r[1])
            ans = max(ans, l[0]+r[0]+root->val);
        return {l[0]+r[0]+root->val, l[1]*r[1], min(l[2],min(r[2],root->val)), max(l[3],max(root->val,r[3]))};
    }
    
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        vector<int>v(4,0);
        call(root, ans, v);
        return ans;
    }
};
