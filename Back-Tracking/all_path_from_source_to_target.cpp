// https://leetcode.com/problems/all-paths-from-source-to-target/submissions/

class Solution {
public:
    void solve(vector<vector<int>> g, vector<vector<int> > &ans, vector<int>v, int i, int n){
        if(i == n){
            ans.push_back(v);
            return;
        }
        for(int j = 0;j < g[i].size();j++){
            v.push_back(g[i][j]);
            solve(g, ans, v, g[i][j], n);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>v = {0};
        vector<vector<int> > ans;
        solve(graph, ans, v, 0, graph.size()-1);
        return ans;
    }
};
