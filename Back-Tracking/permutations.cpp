// https://www.interviewbit.com/old/problems/permutations/

void call(int n, vector<int>A, vector<int>v, vector<vector<int>>&ans, vector<int>num){
    if(v.size() == n){
        ans.push_back(v);
        return;
    }
    for(int i =0;i < n;i++){
        if(!num[i])continue;
        v.push_back(A[i]);
        num[i] = 0;
        call(n, A, v, ans, num);
        num[i] = 1;
        v.pop_back();
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n = A.size();
    vector<int>num(n,1),v;
    vector<vector<int>>ans;
    call(A.size(), A, v, ans, num);
    return ans;
}
