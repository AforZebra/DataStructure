// https://www.interviewbit.com/old/problems/subset/

void call(int idx, vector<int>A, int n, vector<vector<int>> &result, vector<int>v){
    result.push_back(v);
    for(int i = idx;i < n;i++){
        v.push_back(A[i]);
        call(i+1, A, n, result, v);
        v.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > result;
    vector<int>v;
    sort(A.begin(),A.end());
    call(0, A, A.size(), result, v);
    return result;
}
