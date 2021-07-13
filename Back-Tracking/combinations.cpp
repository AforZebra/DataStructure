// https://www.interviewbit.com/old/problems/combinations/

void call(int idx, int count, int A, vector<int>v, vector<vector<int>>&ans){
    if(count == 0){
        ans.push_back(v);
        return;
    }
    if(count < 0)return;
    for(int i = idx; i <= A;i++){
        v.push_back(i);
        call(i+1, count-1, A, v, ans);
        v.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<int>v;
    vector<vector<int>>ans;
    call(1, B, A, v, ans);
    return ans;
}
