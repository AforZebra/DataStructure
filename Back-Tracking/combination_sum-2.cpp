// https://www.interviewbit.com/old/problems/combination-sum-ii/

void call(int idx, int n, int sum, vector<int>A, vector<int>v, set<vector<int>>&s){
    if(sum == 0){
        s.insert(v);
        return;
    }
    if(sum < 0)return;
    for(int i = idx;i < n;i++){
        v.push_back(A[i]);
        call(i+1,n,sum-A[i],A,v,s);
        v.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<int>v;
    vector<vector<int>>ans;
    set<vector<int>>s;
    call(0,A.size(),B,A,v,s);
    for(auto itr = s.begin();itr != s.end();itr++)
        ans.push_back(*itr);
    return ans;
}



// Solution 2

void call(int idx, int n, int sum, vector<int>A, vector<int>v, set<vector<int>>&s){
    if(sum == 0){
        s.insert(v);
        return;
    }
    if(sum < 0 || idx >= n)return;
    v.push_back(A[idx]);
    call(idx+1,n,sum-A[idx],A,v,s);
    v.pop_back();
    call(idx+1,n,sum,A,v,s);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<int>v;
    vector<vector<int>>ans;
    set<vector<int>>s;
    call(0,A.size(),B,A,v,s);
    for(auto itr : s)
        ans.push_back(itr);
    return ans;
}

