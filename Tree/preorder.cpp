// https://www.interviewbit.com/problems/preorder-traversal/

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int>v;
    if(!A)return v;
    TreeNode *curr = A;
    stack<TreeNode *>s;
    while(!s.empty() || curr){
        if(curr){
            v.push_back(curr->val);
            s.push(curr);
            curr = curr->left;
        }
        else{
            curr = s.top()->right;
            s.pop();
        }
    }
    return v;
}
