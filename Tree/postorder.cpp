// https://www.interviewbit.com/old/problems/postorder-traversal/

vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int>v;
    if(!A)return v;
    pair<TreeNode*, int>curr;
    stack<pair<TreeNode *, int>>s;
    s.push({A,0});
    while(!s.empty()){
        curr = s.top();
        if(curr.first->left && curr.second == 0){
            s.top().second = 1;
            s.push({curr.first->left,0});
        }
        else if(curr.first->right && curr.second <= 1){
            s.top().second = 2;
            s.push({curr.first->right,0});
        }
        else{
            v.push_back(curr.first->val);
            s.pop();
        }
    }
    return v;
}
