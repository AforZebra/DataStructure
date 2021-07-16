// https://www.interviewbit.com/old/problems/all-unique-permutations/?ref=similar_problems

void call(int idx, int n, vector<vector<int>>&ans, vector<int>A, set<vector<int>>&s){
    if(idx >= n-1){
        if(s.find(A) == s.end())
            ans.push_back(A);
        s.insert(A);
        return;
    }
    for(int i = idx;i < n;i++){
        swap(A[i],A[idx]);
        call(idx+1, n, ans, A, s);
        swap(A[i],A[idx]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>>ans;
    set<vector<int>>s;
    call(0, A.size(), ans, A, s);
    return ans;
}
