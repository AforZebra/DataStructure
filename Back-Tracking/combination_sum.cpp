// https://www.interviewbit.com/old/problems/combination-sum/

void call(int idx, int sum, int B, vector<int>A, vector<int>v, set<vector<int>>&s){
    if(sum == B)s.insert(v);
    if(sum > B || idx >= A.size() || A[idx] == 0)return;
    v.push_back(A[idx]);
    call(idx, sum+A[idx], B, A, v, s);
    call(idx+1, sum+A[idx], B, A, v, s);
    v.pop_back();
    call(idx+1, sum, B, A, v, s);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    set<vector<int>>s;
    vector<int>v;
    vector<vector<int>>ans;
    sort(A.begin(),A.end());
    call(0,0,B,A,v,s);
    set<vector<int>>::iterator itr;
    for(itr = s.begin(); itr!=s.end();itr++){
        ans.push_back(*itr);
    }
    return ans;
}
