// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    static bool sortBySec(const pair<int,int> &a, const pair<int,int>&b){
        if(a.second == b.second)return a.first < b.first;
        return a.second < b.second;
    }
    
    void call(TreeNode *root, int loc, int level, int left, vector<vector<pair<int,int>>>&ans){
        if(!root)return;
        ans[loc+left].push_back({root->val, level});
        call(root->left, loc-1,level + 1, left, ans);
        call(root->right, loc+1, level + 1, left, ans);
    }
    
    void leftMost(TreeNode *root, int num, int &left, int &right){
        if(!root)return;
        left = min(num, left);
        right = max(num, right);
        leftMost(root->left, num-1, left, right);
        leftMost(root->right, num+1, left, right);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int left = 0, right = 0;
        leftMost(root, 0, left, right);
        vector<vector<pair<int,int> > >ans(abs(left)+right+1);
        vector<vector<int>>ans2(ans.size());
        call(root, 0, 0, abs(left), ans);
        for(int i = 0;i < ans.size();i++){
            sort(ans[i].begin(), ans[i].end(), sortBySec);
        }
        for(int i = 0;i < ans.size();i++){
            for(int j = 0;j < ans[i].size();j++){
                ans2[i].push_back(ans[i][j].first);
            }
        }
        return ans2;
    }
};
